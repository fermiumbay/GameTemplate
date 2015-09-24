#pragma once
#include "includes.h"
#include "Graphic.h"

// �X�N���[���N���X
class Screen{
public:

	// �T�C�Y���w�肵�ăX�N���[������
	static Screen* Create(Vector2 size);

	// �X�N���[���폜
	static void Delete(Screen* screen);

	// �`���̉�ʂ��R�s�[�������̂��X�N���[���Ƃ��Đ���
	static Screen* CreateByDisplay(Vector2 first, Vector2 last);

	// �`�施�߂�����ƃX�N���[���ɓ��e�����
	virtual void Draw(function<void()> func);

	// �O���t�B�b�N�n���h���擾
	GraphicHandle GetHandle();

	// ��ʂ����S�N���A
	void Clear();

private:
	Screen() {}
	virtual ~Screen() {}
	Screen(const Screen&) {}
	const Screen& operator=(const Screen&) {}

	// �X�N���[���̃O���t�B�b�N�n���h��
	GraphicHandle gh;

	// �e���x�����Ƃ̃n���h���X�^�b�N
	static stack<int> handleStack;

	// �n���h���X�^�b�N�̃g�b�v�̃n���h����`���ɐݒ�
	void SetDrawScreenByHandleStack();
};
