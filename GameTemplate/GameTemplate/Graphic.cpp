#include "Graphic.h"

Graphic* Graphic::Create(string path, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	Graphic* ret = new Graphic();
	ret->gh = CreateHandle(path);
	ret->pos = pos;
	ret->fade = fade;
	ret->zoom = zoom;
	ret->angle = angle;
	ret->centerPosFlg = centerPosFlg;
	ret->trans = trans;
	GetGraphSize(ret->gh.handle, &ret->width, &ret->height);
	ret->SetDefaultColor();
	ret->turnFlg = false;
	return ret;
}

vector<Graphic*> Graphic::Create(string path, Vector2 oneSize, Vector2 divNum, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	vector<Graphic*> ret;
	GraphicHandle* gh = CreateHandle(path, oneSize, divNum);
	for (int i = 0; i < divNum.x * divNum.y; i++){
		Graphic* tmp = new Graphic();
		tmp->gh = gh[i];
		tmp->width = oneSize.x;
		tmp->height = oneSize.y;
		tmp->pos = pos;
		tmp->fade = fade;
		tmp->zoom = zoom;
		tmp->angle = angle;
		tmp->centerPosFlg = centerPosFlg;
		tmp->trans = trans;
		tmp->SetDefaultColor();
		tmp->turnFlg = false;
		ret.push_back(tmp);
	}
	delete[] gh;
	return ret;
}

Graphic* Graphic::Create(GraphicHandle gh, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	Graphic* ret = new Graphic();
	ret->gh = gh;
	ret->pos = pos;
	ret->fade = fade;
	ret->zoom = zoom;
	ret->angle = angle;
	ret->centerPosFlg = centerPosFlg;
	ret->trans = trans;
	GetGraphSize(ret->gh.handle, &ret->width, &ret->height);
	ret->SetDefaultColor();
	ret->turnFlg = false;
	return ret;
}

vector<Graphic*> Graphic::Create(GraphicHandle* gh, Vector2d pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	vector<Graphic*> ret;
	for (int i = 0; gh[i].handle != 0; i++){
		Graphic* tmp = new Graphic();
		tmp->gh = gh[i];
		tmp->pos = pos;
		tmp->fade = fade;
		tmp->zoom = zoom;
		tmp->angle = angle;
		tmp->centerPosFlg = centerPosFlg;
		tmp->trans = trans;
		GetGraphSize(tmp->gh.handle, &tmp->width, &tmp->height);
		tmp->SetDefaultColor();
		tmp->turnFlg = false;
		ret.push_back(tmp);
	}
	return ret;
}

Graphic* Graphic::Create(string path, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	return Create(path, pos.ToDouble(), centerPosFlg, trans, fade, zoom, angle);
}

vector<Graphic*> Graphic::Create(string path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	return Create(path, oneSize, divNum, pos.ToDouble(), centerPosFlg, trans, fade, zoom, angle);
}

Graphic* Graphic::Create(GraphicHandle gh, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	return Create(gh, pos.ToDouble(), centerPosFlg, trans, fade, zoom, angle);
}

vector<Graphic*> Graphic::Create(GraphicHandle* gh, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2d zoom, double angle){
	return Create(gh, pos.ToDouble(), centerPosFlg, trans, fade, zoom, angle);
}

void Graphic::Draw(Vector2d addPos){
	int r, g, b;
	GetDrawBright(&r, &g, &b);
	SetDrawBright((color_red * r) / 255, (color_green * g) / 255, (color_blue * b) / 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	if(zoom == Vector2d(100.0, 100.0) && angle == 0.0 && turnFlg == false){
		if(centerPosFlg){
			DrawGraph(static_cast<int>(pos.x + addPos.x - width / 2), static_cast<int>(pos.y + addPos.y - height / 2), gh.handle, trans);
		}else{
			DrawGraph(static_cast<int>(pos.x + addPos.x), static_cast<int>(pos.y + addPos.y), gh.handle, trans);
		}
	}else{
		int x, y;
		x = static_cast<int>(pos.x + addPos.x);
		y = static_cast<int>(pos.y + addPos.y);
		if (!centerPosFlg){
			double zx, zy;
			zx = static_cast<double>(zoom.x * width) / 200.0;
			zy = static_cast<double>(zoom.y * height) / 200.0;
			x += static_cast<int>(zy * sin(angle) + zx * cos(angle));
			y += static_cast<int>(zy * cos(angle) - zx * sin(angle));
		}
		DrawRotaGraph3(x, y, width / 2, height / 2, 0.01 * zoom.x, 0.01 * zoom.y, -angle, gh.handle, trans, turnFlg);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(r, g, b);
}

int Graphic::GetWidth(){
	return width;
}

int Graphic::GetHeight(){
	return height;
}

void Graphic::SetColor(int red, int green, int blue){
	color_red = red;
	color_green = green;
	color_blue = blue;
}

void Graphic::SetDefaultColor(){
	SetColor(255, 255, 255);
}

void Graphic::SetZoom(Vector2d zoom){
	this->zoom = zoom;
}

void Graphic::SetZoom(double zoom){
	this->zoom = Vector2d(zoom, zoom);
}

GraphicHandle Graphic::CreateHandle(string path){
	return LoadGraph(path.c_str());
}

GraphicHandle* Graphic::CreateHandle(string path, Vector2 oneSize, Vector2 divNum){
	GraphicHandle* ret = new GraphicHandle[divNum.x * divNum.y + 1];
	LoadDivGraph(path.c_str(), divNum.x * divNum.y, divNum.x, divNum.y, oneSize.x, oneSize.y, &ret->handle);
	ret[divNum.x * divNum.y].handle = 0;	// 終端
	return ret;
}

void Graphic::Delete(Graphic* graph){
	DeleteGraph(graph->gh.handle);
	delete graph;
}

void Graphic::Delete(vector<Graphic*> graph){
	DeleteGraph(graph[0]->gh.handle);	// これで全部消えるか？
	for (vector<Graphic*>::iterator it = graph.begin(); it != graph.end(); it++){
		delete *it;
	}
}

void Graphic::Delete(GraphicHandle gh){
	DeleteGraph(gh.handle);
}

void Graphic::Delete(GraphicHandle* gh){
	DeleteGraph(gh[0].handle);	// これで全部消えるか？
}
