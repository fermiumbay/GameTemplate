#include "Font.h"

Font* Font::Create(string fontName, Vector2d pos, int size, int thick, bool edgeFlg, FontType type){
	Font* ret = new Font();
	int fontType;

	switch (type){
	case FontType::normal:
		if (!edgeFlg){
			fontType = DX_FONTTYPE_NORMAL;
		}
		else{
			fontType = DX_FONTTYPE_EDGE;
		}
		break;
	case FontType::antialiasing:
		if (!edgeFlg){
			fontType = DX_FONTTYPE_ANTIALIASING;
		}
		else{
			fontType = DX_FONTTYPE_ANTIALIASING_EDGE;
		}
		break;
	case FontType::antialiasing_4x4:
		if (!edgeFlg){
			fontType = DX_FONTTYPE_ANTIALIASING_4X4;
		}
		else{
			fontType = DX_FONTTYPE_ANTIALIASING_EDGE_4X4;
		}
		break;
	case FontType::antialiasing_8x8:
		if (!edgeFlg){
			fontType = DX_FONTTYPE_ANTIALIASING_8X8;
		}
		else{
			fontType = DX_FONTTYPE_ANTIALIASING_EDGE_8X8;
		}
		break;
	}
	ret->handle = CreateFontToHandle(fontName.c_str(), size, thick, fontType);
	ret->pos = pos;
	ret->SetColor(255, 255, 255);
	ret->SetEdgeColor(0, 0, 0);
	return ret;
}

void Font::Delete(Font* font){
	DeleteFontToHandle(font->handle);
	delete font;
}

void Font::SetColor(int r, int g, int b){
	color_r = r;
	color_g = g;
	color_b = b;
}

void Font::SetEdgeColor(int r, int g, int b){
	edgeColor_r = r;
	edgeColor_g = g;
	edgeColor_b = b;
}

void Font::Print(string text, Vector2d addPos){
	DrawStringToHandle(
		static_cast<int>(pos.x + addPos.x),
		static_cast<int>(pos.y + addPos.y),
		text.c_str(),
		GetColor(color_r, color_g, color_b),
		handle,
		GetColor(edgeColor_r, edgeColor_g, edgeColor_b)
		);
}
