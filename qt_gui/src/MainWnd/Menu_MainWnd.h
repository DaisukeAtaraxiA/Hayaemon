﻿//----------------------------------------------------------------------------
// Menu_MainWnd.h : メインウィンドウ用メニューの作成・管理を行う
//----------------------------------------------------------------------------
#ifndef Menu_MainWndH
#define Menu_MainWndH

#include <unordered_map>
#include <QObject>
#include "../Common/Define.h"
class CMainWnd;
class QAction;
//----------------------------------------------------------------------------
// メインウィンドウ用メニューの作成・管理を行うクラス
//----------------------------------------------------------------------------
class CMenu_MainWnd : public QObject
{
public: // 関数

	CMenu_MainWnd(CMainWnd & mainWnd)
		: m_rMainWnd(mainWnd) { }

	virtual BOOL Create();
	void SetABLoopState(BOOL bALoop, BOOL bBLoop);
	void SetSingleLoopState(BOOL bSLoop);
	void SwitchEQVisible(UINT uID);
	void SwitchItemChecked(UINT uID);
	void OnSpeedMenuSelected(bool checked);
	void OnFreqMenuSelected(bool checked);
	void OnPitchMenuSelected(bool checked);
	void OnVolumeMenuSelected(bool checked);
	void OnPanMenuSelected(bool checked);
	void OnEQMenuSelected(bool checked);
	void OnHeadMenuSelected();
	void OnPauseMenuSelected();
	void OnPreviousMenuSelected();
	void OnNextMenuSelected();
	void OnStopMenuSelected();
	void OnRewindMenuSelected(bool checked);
	void OnForwardMenuSelected(bool checked);
	void OnReturn1SecMenuSelected();
	void OnReturn2SecMenuSelected();
	void OnReturn3SecMenuSelected();
	void OnReturn5SecMenuSelected();
	void OnReturn10SecMenuSelected();
	void OnForward1SecMenuSelected();
	void OnForward2SecMenuSelected();
	void OnForward3SecMenuSelected();
	void OnForward5SecMenuSelected();
	void OnForward10SecMenuSelected();
	void OnResetSpeedMenuSelected();
	void OnSetSpeed50MenuSelected();
	void OnSetSpeed60MenuSelected();
	void OnSetSpeed70MenuSelected();
	void OnSetSpeed80MenuSelected();
	void OnSetSpeed90MenuSelected();
	void OnSetSpeed100MenuSelected();
	void OnSetSpeed110MenuSelected();
	void OnSetSpeed120MenuSelected();
	void OnSetSpeed130MenuSelected();
	void OnSetSpeed140MenuSelected();
	void OnSetSpeed150MenuSelected();
	void OnSetSpeed160MenuSelected();
	void OnSetSpeed170MenuSelected();
	void OnSetSpeed180MenuSelected();
	void OnSetSpeed190MenuSelected();
	void OnSetSpeed200MenuSelected();
	void OnSetSpeed250MenuSelected();
	void OnSetSpeed300MenuSelected();
	void OnSetSpeed350MenuSelected();
	void OnSetSpeed400MenuSelected();
	void OnDown0_1SpeedMenuSelected();
	void OnDown1SpeedMenuSelected();
	void OnDown2SpeedMenuSelected();
	void OnDown3SpeedMenuSelected();
	void OnDown5SpeedMenuSelected();
	void OnDown10SpeedMenuSelected();
	void OnUp0_1SpeedMenuSelected();
	void OnUp1SpeedMenuSelected();
	void OnUp2SpeedMenuSelected();
	void OnUp3SpeedMenuSelected();
	void OnUp5SpeedMenuSelected();
	void OnUp10SpeedMenuSelected();
	void OnSetSpeedDecimal0MenuSelected();
	void OnSetSpeedDecimal1MenuSelected();
	void OnSetSpeedDecimal2MenuSelected();
	void OnResetFreqMenuSelected();
	void OnSetFreq50MenuSelected();
	void OnSetFreq60MenuSelected();
	void OnSetFreq70MenuSelected();
	void OnSetFreq80MenuSelected();
	void OnSetFreq90MenuSelected();
	void OnSetFreq100MenuSelected();
	void OnSetFreq110MenuSelected();
	void OnSetFreq120MenuSelected();
	void OnSetFreq130MenuSelected();
	void OnSetFreq140MenuSelected();
	void OnSetFreq150MenuSelected();
	void OnSetFreq160MenuSelected();
	void OnSetFreq170MenuSelected();
	void OnSetFreq180MenuSelected();
	void OnSetFreq190MenuSelected();
	void OnSetFreq200MenuSelected();
	void OnSetFreq250MenuSelected();
	void OnSetFreq300MenuSelected();
	void OnSetFreq350MenuSelected();
	void OnSetFreq400MenuSelected();
	void OnDown0_1FreqMenuSelected();
	void OnDown1FreqMenuSelected();
	void OnDown2FreqMenuSelected();
	void OnDown3FreqMenuSelected();
	void OnDown5FreqMenuSelected();
	void OnDown10FreqMenuSelected();
	void OnUp0_1FreqMenuSelected();
	void OnUp1FreqMenuSelected();
	void OnUp2FreqMenuSelected();
	void OnUp3FreqMenuSelected();
	void OnUp5FreqMenuSelected();
	void OnUp10FreqMenuSelected();
	void OnSetFreqDecimal0MenuSelected();
	void OnSetFreqDecimal1MenuSelected();
	void OnSetFreqDecimal2MenuSelected();
	void OnResetPitchMenuSelected();
	void OnSetPitchFlat12MenuSelected();
	void OnSetPitchFlat11MenuSelected();
	void OnSetPitchFlat10MenuSelected();
	void OnSetPitchFlat9MenuSelected();
	void OnSetPitchFlat8MenuSelected();
	void OnSetPitchFlat7MenuSelected();
	void OnSetPitchFlat6MenuSelected();
	void OnSetPitchFlat5MenuSelected();
	void OnSetPitchFlat4MenuSelected();
	void OnSetPitchFlat3MenuSelected();
	void OnSetPitchFlat2MenuSelected();
	void OnSetPitchFlat1MenuSelected();
	void OnSetPitchNaturalMenuSelected();
	void OnSetPitchSharp1MenuSelected();
	void OnSetPitchSharp2MenuSelected();
	void OnSetPitchSharp3MenuSelected();
	void OnSetPitchSharp4MenuSelected();
	void OnSetPitchSharp5MenuSelected();
	void OnSetPitchSharp6MenuSelected();
	void OnSetPitchSharp7MenuSelected();
	void OnSetPitchSharp8MenuSelected();
	void OnSetPitchSharp9MenuSelected();
	void OnSetPitchSharp10MenuSelected();
	void OnSetPitchSharp11MenuSelected();
	void OnSetPitchSharp12MenuSelected();
	void OnDown1PitchMenuSelected();
	void OnDown2PitchMenuSelected();
	void OnDown1OctavePitchMenuSelected();
	void OnUp1PitchMenuSelected();
	void OnUp2PitchMenuSelected();
	void OnUp1OctavePitchMenuSelected();
	void OnSetPitchDecimal0MenuSelected();
	void OnSetPitchDecimal1MenuSelected();
	void OnSetPitchDecimal2MenuSelected();
	void OnResetVolumeMenuSelected();
	void OnSetVolume0MenuSelected();
	void OnSetVolume10MenuSelected();
	void OnSetVolume20MenuSelected();
	void OnSetVolume30MenuSelected();
	void OnSetVolume40MenuSelected();
	void OnSetVolume50MenuSelected();
	void OnSetVolume60MenuSelected();
	void OnSetVolume70MenuSelected();
	void OnSetVolume80MenuSelected();
	void OnSetVolume90MenuSelected();
	void OnSetVolume100MenuSelected();
	void OnSingleLoopMenuSelected();
	void OnAllLoopMenuSelected(bool checked);
	void OnRandomMenuSelected(bool checked);
	void OnContinueMenuSelected(bool checked);
	void OnABLoopAMenuSelected();
	void OnABLoopASettingMenuSelected();
	void OnABLoopBMenuSelected();
	void OnABLoopBSettingMenuSelected();
	void OnMarkerPlayMenuSelected();
	void OnAddMarkerMenuSelected();
	void OnDeleteMarkerMenuSelected();
	void OnCountLoopMenuSelected();
	void OnInstantLoopMenuSelected();
	void OnSetPositionAutoMenuSelected();

private: // メンバ変数

	CMainWnd & m_rMainWnd;
	std::unordered_map<UINT, QAction*> m_actionMap;

	friend class CMainWnd;

public:
	// Qtのラッパー
	void CheckItem(UINT uIDCheckItem, UINT uCheck);
	BOOL IsItemChecked(UINT uID);
	void EnableItem(UINT uIDEnableItem, UINT uEnable);

private:
	// Qtのラッパー
	void CreateActionMap();
	void CreateActionGroups();
	void CreateConnections();
};
//----------------------------------------------------------------------------

#endif
