#include "Graphic.h"

GraphicHandle Graphic::CreateHandle(string path) {
	GraphicHandle ret;
	ret.handle = new int[1];
	ret.handle[0] = LoadGraph(path.c_str());
	while (CheckHandleASyncLoad(ret.handle[0]) == TRUE) {
		ProcessMessage();
		Sleep(1);
	}
	ret.divNum = Vector2(1, 1);
	ret.patternNum = Vector2(1, 1);
	return ret;
}

GraphicHandle Graphic::CreateHandle(string path, Vector2 oneSize, Vector2 patternNum) {
	return CreateDivHandle(path, oneSize, Vector2(1, 1), patternNum);
}

GraphicHandle Graphic::CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum) {
	return CreateDivHandle(path, oneSize, divNum, Vector2(1, 1));
}

GraphicHandle Graphic::CreateDivHandle(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum) {
	GraphicHandle ret;
	int x = divNum.x * patternNum.x;
	int y = divNum.y * patternNum.y;
	ret.handle = new int[x * y];
	LoadDivGraph(path.c_str(), x * y, x, y, oneSize.x, oneSize.y, ret.handle);
	int loadNum = 0;
	while (loadNum < x * y) {
		loadNum = 0;
		for (int i = 0; i < x * y; i++) {
			if (CheckHandleASyncLoad(ret.handle[i]) != TRUE) {
				loadNum++;
			}
		}
		ProcessMessage();
		Sleep(1);
	}
	ret.divNum = divNum;
	ret.patternNum = patternNum;
	return ret;
}

void Graphic::DeleteHandle(GraphicHandle handle) {
	delete[] handle.handle;
}

void Graphic::SetValues(Vector2d pos, int fade, Vector2d zoom, double angle, bool centerPosFlg, bool trans, BlendMode blendMode, bool bilinearFlg) {
	this->pos = pos;
	this->fade = fade;
	this->zoom = zoom;
	this->angle = angle;
	this->centerPosFlg = centerPosFlg;
	this->trans = trans;
	this->SetDefaultColor();
	this->turnFlg = false;
	this->blendMode = blendMode;
	this->bilinearFlg = bilinearFlg;
}

Graphic* Graphic::Create(string path, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	Graphic* ret = new Graphic();
	ret->gh = CreateHandle(path);
	ret->SetValues(pos, fade, zoom, angle, centerPosFlg, trans, blendMode, bilinearFlg);
	GetGraphSize(ret->gh.handle[0], &ret->width, &ret->height);
	ret->createByHandleFlg = false;
	return ret;
}

Graphic* Graphic::Create(string path, Vector2 oneSize, Vector2 patternNum, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	Graphic* ret = new Graphic();
	ret->gh = CreateHandle(path, oneSize, patternNum);
	ret->SetValues(pos, fade, zoom, angle, centerPosFlg, trans, blendMode, bilinearFlg);
	GetGraphSize(ret->gh.handle[0], &ret->width, &ret->height);
	ret->createByHandleFlg = false;
	return ret;
}

Graphic* Graphic::Create(GraphicHandle gh, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	Graphic* ret = new Graphic();
	ret->gh = gh;
	ret->SetValues(pos, fade, zoom, angle, centerPosFlg, trans, blendMode, bilinearFlg);
	GetGraphSize(ret->gh.handle[0], &ret->width, &ret->height);
	ret->createByHandleFlg = true;
	return ret;
}

vector<Graphic*> Graphic::CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	return CreateDiv(path, oneSize, divNum, Vector2(1, 1), pos, centerPosFlg, trans, fade, zoom, angle, blendMode, bilinearFlg);
}

vector<Graphic*> Graphic::CreateDiv(string path, Vector2 oneSize, Vector2 divNum, Vector2 patternNum, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	GraphicHandle gh = CreateDivHandle(path, oneSize, divNum, patternNum);
	vector<Graphic*> ret = CreateDiv(gh, pos, centerPosFlg, trans, fade, zoom, angle, blendMode, bilinearFlg);
	for (auto data : ret) {
		data->createByHandleFlg = false;
	}
	DeleteHandle(gh.handle);
	return ret;
}

vector<Graphic*> Graphic::CreateDiv(GraphicHandle gh, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle, BlendMode blendMode, bool bilinearFlg) {
	vector<Graphic*> ret;
	int ix = gh.divNum.x * gh.patternNum.x, iy = gh.divNum.y * gh.patternNum.y;
	for (int i = 0; i < gh.divNum.x * gh.divNum.y; i++) {
		Graphic* tmp = new Graphic();
		tmp->gh.handle = new int[gh.patternNum.x * gh.patternNum.y];
		tmp->SetValues(pos, fade, zoom, angle, centerPosFlg, trans, blendMode, bilinearFlg);
		GetGraphSize(gh.handle[0], &tmp->width, &tmp->height);
		tmp->createByHandleFlg = true;
		ret.push_back(tmp);
	}
	for (int i = 0; i < ix * iy; i++) {
		int d = (i / gh.patternNum.x) % gh.divNum.x + gh.divNum.x * (i / (ix * gh.patternNum.y));
		int p = ((i % gh.patternNum.x) + gh.patternNum.x * (i / ix)) % (gh.patternNum.x * gh.patternNum.y);
		ret[d]->gh.handle[p] = gh.handle[i];
	}
	return ret;
}

void Graphic::Delete(Graphic* graph) {
	if (!graph->createByHandleFlg) {
		DeleteGraph(graph->gh.handle[0]);
		DeleteHandle(graph->gh);
	}
	delete graph;
}

void Graphic::Delete(GraphicHandle gh) {
	DeleteGraph(gh.handle[0]);
	DeleteHandle(gh);
}

void Graphic::DeleteDiv(vector<Graphic*> graph) {
	if (!graph[0]->createByHandleFlg) {
		DeleteGraph(graph[0]->gh.handle[0]);
	}
	for (auto data : graph) {
		DeleteHandle(data->gh.handle);
		delete data;
	}
}

void Graphic::Draw(int id, Vector2d addPos) {
	int r, g, b;
	GetDrawBright(&r, &g, &b);
	SetDrawBright((color.GetR() * r) / 255, (color.GetG() * g) / 255, (color.GetB() * b) / 255);
	if (bilinearFlg) {
		SetDrawMode(DX_DRAWMODE_BILINEAR);	// バイリニア描画
	}
	else {
		SetDrawMode(DX_DRAWMODE_NEAREST);	// ネアレストネイバー描画
	}
	SetDrawBlendMode(blendMode, fade);	// ブレンドモードを切り替えられるように
	if (zoom == Vector2d(100.0, 100.0) && angle == 0.0 && turnFlg == false) {
		if (centerPosFlg) {
			DrawGraph(static_cast<int>(pos.x + addPos.x - width / 2), static_cast<int>(pos.y + addPos.y - height / 2), gh.handle[id], trans);
		}
		else {
			DrawGraph(static_cast<int>(pos.x + addPos.x), static_cast<int>(pos.y + addPos.y), gh.handle[id], trans);
		}
	}
	else {
		int x, y;
		x = static_cast<int>(pos.x + addPos.x);
		y = static_cast<int>(pos.y + addPos.y);
		if (!centerPosFlg) {
			double zx, zy;
			zx = static_cast<double>(zoom.x * width) / 200.0;
			zy = static_cast<double>(zoom.y * height) / 200.0;
			x += static_cast<int>(zy * sin(angle) + zx * cos(angle));
			y += static_cast<int>(zy * cos(angle) - zx * sin(angle));
		}
		DrawRotaGraph3(x, y, width / 2, height / 2, 0.01 * zoom.x, 0.01 * zoom.y, -angle, gh.handle[id], trans, turnFlg);
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(r, g, b);
}

int Graphic::GetWidth() {
	return width;
}

int Graphic::GetHeight() {
	return height;
}

void Graphic::SetColor(Color c) {
	color = c;
}

void Graphic::SetDefaultColor() {
	SetColor(Color::White());
}

void Graphic::SetZoom(Vector2d zoom) {
	this->zoom = zoom;
}

void Graphic::SetZoom(double zoom) {
	this->zoom = Vector2d(zoom, zoom);
}

bool Graphic::GetCenterPosFlg() {
	return centerPosFlg;
}
