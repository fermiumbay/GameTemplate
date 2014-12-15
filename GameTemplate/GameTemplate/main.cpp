#include "Game.h"

// ���C������
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// ���������[�N���o

	//���������i�G���[��������ƏI���j
	if (SetWindowIconID(101) != 0){ return 0; }	// �A�C�R���摜�̖��ߍ���
	if (SetOutApplicationLogValidFlag(false) != 0){ return 0; }	// ���O�o�͂��֎~����
	if (SetGraphMode(InfoData::WindowSize().x, InfoData::WindowSize().y, InfoData::WindowColorBitNum()) != 0){ return 0; }	// �𑜓x�̐ݒ�
	if (SetMainWindowText(InfoData::GameTitle().c_str())){ return 0; }	// �^�C�g���o�[�̏����e�L�X�g������
	if (ChangeWindowMode(InfoData::WindowMode()) != 0){ return 0; }	//�E�B���h�E���[�h�ɐݒ�
	if (DxLib_Init() != 0){ return 0; }	//DX���C�u��������������
	if (SetDrawScreen(DX_SCREEN_BACK) != 0){ return 0; }	//�`���𗠉�ʂɐݒ�
	if (SetChangeScreenModeGraphicsSystemResetFlag(false)){ return 0; }	// �X�N���[�����[�h�ύX�ɂ��摜�֌W�̐ݒ菉�������֎~

	Random::DefaultRand();	// �����̏�����
	CommonData::Initialize();	// �f�[�^�̏�����
	KeyInput::Initialize();	// �L�[���͂̏�����
	Game game;	// �Q�[���I�u�W�F�N�g
	
	//�J��Ԃ������i�G���[��������ƏI���j
	do{
		if(ScreenFlip() != 0){break;}	//����ʂ�\��ʂɔ��f
		if(ProcessMessage() != 0){break;}	//Windows�Ƃ̓���
		if(ClearDrawScreen() != 0){break;}	//��ʂ�����
		game.Play();	// �Q�[�������̎��s
	}while(!game.Exit());	// �Q�[���̏I��

	CommonData::Finalize();	// ���ʃf�[�^�̏I������
    DxLib_End();    // DX���C�u�����I������
    return 0;
}
