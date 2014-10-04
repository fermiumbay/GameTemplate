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
	ret->SetColor(Color::White());
	ret->SetEdgeColor(Color::Black());
	return ret;
}

void Font::Delete(Font* font){
	DeleteFontToHandle(font->handle);
	delete font;
}

void Font::SetColor(Color c){
	color = c;
}

void Font::SetEdgeColor(Color c){
	edgeColor = c;
}

void Font::Print(string text, Vector2d addPos, Color color, Color edgeColor){
	if (color.HasNotColor()){
		color = this->color;
	}
	if (edgeColor.HasNotColor()){
		edgeColor = this->edgeColor;
	}
	DrawStringToHandle(
		static_cast<int>(pos.x + addPos.x),
		static_cast<int>(pos.y + addPos.y),
		text.c_str(),
		GetColor(color.GetR(), color.GetG(), color.GetB()),
		handle,
		GetColor(edgeColor.GetR(), edgeColor.GetG(), edgeColor.GetB())
		);
}
