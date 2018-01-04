﻿//----------------------------------------------------------------------------
// ToolBar_MainWnd.cpp : メインウィンドウ用ツールバーの作成・管理を行う
//----------------------------------------------------------------------------
#include "ToolBar_MainWnd.h"
#include <cassert>
#include "../Common/CommandList.h"
#include "MainWnd.h"

enum {
	ID_PLAY,
	ID_PAUSE,
	ID_STOP,
	ID_ABLOOP_A,
	ID_ABLOOP_B,
};
//----------------------------------------------------------------------------
// コンストラクタ
//----------------------------------------------------------------------------
CToolBar_MainWnd::CToolBar_MainWnd(CMainWnd & mainWnd)
	: m_rMainWnd(mainWnd),
		m_buttonMap({{ID_PLAY, m_rMainWnd.playButton},
								 {ID_PAUSE, m_rMainWnd.pauseButton},
								 {ID_STOP, m_rMainWnd.stopButton},
								 {ID_SLOOP, m_rMainWnd.singleLoopButton},
								 {ID_ALOOP, m_rMainWnd.allLoopButton},
								 {ID_RANDOM, m_rMainWnd.randomPlayButton},
								 {ID_ABLOOP_A, m_rMainWnd.abLoopAButton},
								 {ID_ABLOOP_B, m_rMainWnd.abLoopBButton}})
{
}
//----------------------------------------------------------------------------
// 作成
//----------------------------------------------------------------------------
BOOL CToolBar_MainWnd::Create()
{
	HideButton(ID_PAUSE, TRUE);

	CreateConnections();

	return TRUE;
}
//----------------------------------------------------------------------------
// ＡＢループの状態を設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::SetABLoopState(BOOL bALoop, BOOL bBLoop)
{
	CheckButton(ID_ABLOOP_A, bALoop);
	CheckButton(ID_ABLOOP_B, bBLoop);
}
//----------------------------------------------------------------------------
// 再生状態を設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::SetPlayingState(BOOL bPlaying)
{
	HideButton(ID_PLAY, bPlaying);
	HideButton(ID_PAUSE, !bPlaying);
	CheckButton(ID_PAUSE, FALSE);
}
//----------------------------------------------------------------------------
// 一時停止状態を設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::SetPausingState(BOOL bPausing)
{
	CheckButton(ID_PAUSE, bPausing);
}
//----------------------------------------------------------------------------
// １曲ループの状態を設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::SetSingleLoopState(BOOL bSLoop)
{
	CheckButton(ID_SLOOP, bSLoop);
	EnableButton(ID_ALOOP, !bSLoop);
	EnableButton(ID_RANDOM, !bSLoop);
}
//----------------------------------------------------------------------------
// １曲ループボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnSingleLoopButtonSelected()
{
	m_rMainWnd.SetSingleLoop();
}
//----------------------------------------------------------------------------
// 全曲ループボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnAllLoopButtonSelected(bool checked)
{
	m_rMainWnd.SetAllLoop(checked);
}
//----------------------------------------------------------------------------
// ランダム再生ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnRandomButtonSelected(bool checked)
{
	m_rMainWnd.SetRandom(checked);
}
//----------------------------------------------------------------------------
// 再生ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnPlayButtonSelected()
{
	m_rMainWnd.Play();
}
//----------------------------------------------------------------------------
// 一時停止ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnPauseButtonSelected()
{
	m_rMainWnd.Pause();
}
//----------------------------------------------------------------------------
// 停止ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnStopButtonSelected()
{
	m_rMainWnd.Stop(FALSE);
}
//----------------------------------------------------------------------------
// ＡＢループ（Ａ）ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnABLoopAButtonSelected()
{
	m_rMainWnd.SetABLoopA();
}
//----------------------------------------------------------------------------
// ＡＢループ（Ｂ）ボタンが選択された
//----------------------------------------------------------------------------
void CToolBar_MainWnd::OnABLoopBButtonSelected()
{
	m_rMainWnd.SetABLoopB();
}
//----------------------------------------------------------------------------
// チェック状態の設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::CheckButton(int nID, BOOL fCheck)
{
	auto it = m_buttonMap.find(nID);
	assert(it != m_buttonMap.end());
	if (it == m_buttonMap.end()) {
		return;
	}
	auto button = it->second;
	assert(button->isCheckable());
	button->setChecked(fCheck ? true : false);
}
//----------------------------------------------------------------------------
// 有効状態の設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::EnableButton(int nID, BOOL fEnable)
{
	auto it = m_buttonMap.find(nID);
	assert(it != m_buttonMap.end());
	if (it == m_buttonMap.end()) {
		return;
	}
	auto button = it->second;
	button->setEnabled(fEnable ? true : false);
}
//----------------------------------------------------------------------------
// 表示状態の設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::HideButton(int nID, BOOL fHide)
{
	auto it = m_buttonMap.find(nID);
	assert(it != m_buttonMap.end());
	if (it == m_buttonMap.end()) {
		return;
	}
	auto button = it->second;
	button->setVisible(fHide ? false : true);
}
//----------------------------------------------------------------------------
// シグナル&スロットの設定
//----------------------------------------------------------------------------
void CToolBar_MainWnd::CreateConnections()
{
	connect(m_rMainWnd.playButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnPlayButtonSelected);
	connect(m_rMainWnd.pauseButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnPauseButtonSelected);
	connect(m_rMainWnd.stopButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnStopButtonSelected);
	connect(m_rMainWnd.singleLoopButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnSingleLoopButtonSelected);
	connect(m_rMainWnd.allLoopButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnAllLoopButtonSelected);
	connect(m_rMainWnd.randomPlayButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnRandomButtonSelected);
	connect(m_rMainWnd.abLoopAButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnABLoopAButtonSelected);
	connect(m_rMainWnd.abLoopBButton, &QToolButton::clicked,
					this, &CToolBar_MainWnd::OnABLoopBButtonSelected);
}
//----------------------------------------------------------------------------
