#include "Graphic.h"

Graphic::Graphic(){
}

Graphic::Graphic(const TCHAR *path, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2 zoom, double angle){
	this->handle = CreateHandle(path);
	this->pos = pos;
	this->fade = fade;
	this->zoom = zoom;
	this->angle = angle;
	this->centerPosFlg = centerPosFlg;
	this->trans = trans;
	GetGraphSize(*(this->handle), &width, &height);
	SetDefaultColor();
	turnFlg = false;
	this->handleNotDeleteFlg = false;
}

Graphic::Graphic(const TCHAR *path, Vector2 oneSize, Vector2 divNum, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2 zoom, double angle){
	this->width = oneSize.x;
	this->height = oneSize.y;
	this->handle = CreateHandle(path, oneSize, divNum);
	this->pos = pos;
	this->fade = fade;
	this->zoom = zoom;
	this->angle = angle;
	this->centerPosFlg = centerPosFlg;
	this->trans = trans;
	SetDefaultColor();
	turnFlg = false;
	this->handleNotDeleteFlg = false;
}

Graphic::Graphic(int *handle, Vector2 pos, bool centerPosFlg, bool trans, int fade, Vector2 zoom, double angle){
	this->handle = handle;
	this->pos = pos;
	this->fade = fade;
	this->zoom = zoom;
	this->angle = angle;
	this->centerPosFlg = centerPosFlg;
	this->trans = trans;
	GetGraphSize(*(this->handle), &width, &height);
	SetDefaultColor();
	turnFlg = false;
	this->handleNotDeleteFlg = true;
}

Graphic::~Graphic(){
	if(!handleNotDeleteFlg){
		DeleteHandle(handle);
	}
}

void Graphic::Draw(int number, Vector2 addPos){
	int r, g, b;
	GetDrawBright(&r, &g, &b);
	SetDrawBright((color_red * r) / 255, (color_green * g) / 255, (color_blue * b) / 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, fade);
	if(zoom == Vector2(100, 100) && angle == 0.0 && turnFlg == false){
		if(centerPosFlg){
			DrawGraph(pos.x + addPos.x - width / 2, pos.y + addPos.y - height / 2, handle[number], trans);
		}else{
			DrawGraph(pos.x + addPos.x, pos.y + addPos.y, handle[number], trans);
		}
	}else{
		int x, y;
		if(centerPosFlg){
			x = pos.x + addPos.x;
			y = pos.y + addPos.y;
		}else{
			double zx, zy;
			zx = static_cast<double>(zoom.x * width) / 200.0;
			zy = static_cast<double>(zoom.y * height) / 200.0;
			x = pos.x + addPos.x + static_cast<int>(zy * sin(angle) + zx * cos(angle));
			y = pos.y + addPos.y + static_cast<int>(zy * cos(angle) - zx * sin(angle));
		}
		DrawRotaGraph3(x, y, width / 2, height / 2, 0.01 * static_cast<double>(zoom.x), 0.01 * static_cast<double>(zoom.y), -angle, handle[number], trans, turnFlg);
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

void Graphic::SetZoom(Vector2 zoom){
	this->zoom = zoom;
}

void Graphic::SetZoom(int zoom){
	this->zoom = Vector2(zoom, zoom);
}

int* Graphic::CreateHandle(const TCHAR *path){
	return new int(LoadGraph(path));
}

int* Graphic::CreateHandle(const TCHAR *path, Vector2 oneSize, Vector2 divNum){
	int* ret = new int[divNum.x * divNum.y];
	LoadDivGraph(path, divNum.x * divNum.y, divNum.x, divNum.y, oneSize.x, oneSize.y, ret);
	return ret;
}

void Graphic::DeleteHandle(int* handle){
	DeleteGraph(*handle);
	delete handle;
}
