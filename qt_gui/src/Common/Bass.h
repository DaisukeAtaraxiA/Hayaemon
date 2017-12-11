﻿//----------------------------------------------------------------------------
// Bass.h : bass.dll の管理を行う
//----------------------------------------------------------------------------
#ifndef BassH
#define BassH

#include "bass/bass.h"
#include "bass/bass_ape.h"
#if _WIN32
#include "bass/bass_aac.h"
#include "bass/bassalac.h"
#include "bass/basscd.h"
#endif
#include "bass/bassflac.h"
#include "Define.h"

#ifdef _UNICODE
#define BASS_IF_UNICODE		BASS_UNICODE
#else // _UNICODE
#define BASS_IF_UNICODE		0
#endif // _UNICODE
//----------------------------------------------------------------------------
// bass.dll の管理を行うクラス
//----------------------------------------------------------------------------
class CBass
{
public: // 関数

	CBass(): m_hStream(0), m_hSync(0) { }
	virtual ~CBass() { Destroy(); }

	virtual void Destroy() {
		BASS_Free();
	}
	virtual double ChannelBytes2Seconds(QWORD pos) const {
		return BASS_ChannelBytes2Seconds(m_hStream, pos);
	}
	virtual float ChannelGetFreq() const {
		float freq;
		BASS_ChannelGetAttribute(m_hStream, BASS_ATTRIB_FREQ, &freq);
		return freq;
	}
	virtual QWORD ChannelGetLength() const {
		return BASS_ChannelGetLength(m_hStream, 0);
	}
	virtual QWORD ChannelGetPosition() const {
		return BASS_ChannelGetPosition(m_hStream, 0);
	}
	virtual double ChannelGetSecondsLength() const {
		return ChannelBytes2Seconds(ChannelGetLength());
	}
	virtual double ChannelGetSecondsPosition() const {
		return ChannelBytes2Seconds(ChannelGetPosition());
	}
	virtual DWORD ChannelIsActive() const {
		return BASS_ChannelIsActive(m_hStream);
	}
	virtual BOOL ChannelIsPausing() const {
		if(ChannelIsActive() == BASS_ACTIVE_PAUSED)
			return TRUE;
		return FALSE;
	}
	virtual BOOL ChannelIsStopped() const {
		if(ChannelIsActive() == BASS_ACTIVE_STOPPED)
			return TRUE;
		return FALSE;
	}
	virtual BOOL ChannelPause() {
		return BASS_ChannelPause(m_hStream);
	}
	virtual BOOL ChannelPlay() {
		return BASS_ChannelPlay(m_hStream, FALSE);
	}
	virtual BOOL ChannelRemoveSync() {
		return BASS_ChannelRemoveSync(m_hStream, m_hSync);
	}
	virtual HFX ChannelSetFX(DWORD type, int priority) {
		return BASS_ChannelSetFX(m_hStream, type, priority);
	}
	virtual BOOL ChannelSetAttribute(DWORD attrib, float value) {
		return BASS_ChannelSetAttribute(m_hStream, attrib, value);
	}
	virtual BOOL ChannelSetPan(int pan) {
		return BASS_ChannelSetAttribute(m_hStream, BASS_ATTRIB_PAN,
										(float)pan / 100.0f);
	}
	virtual BOOL ChannelSetPosition(QWORD pos) {
		return BASS_ChannelSetPosition(m_hStream, pos, 0);
	}
	virtual BOOL ChannelStop() {
		return BASS_ChannelStop(m_hStream);
	}
	virtual void ChannelSetSync(DWORD type, QWORD param, SYNCPROC *proc,
								DWORD *user) {
		m_hSync = BASS_ChannelSetSync(m_hStream, type, param, proc, user);
	}
	virtual BOOL Init() {
		return BASS_Init(-1, 44100, 0, 0, NULL);
	}
	virtual BOOL StreamCreateFile(LPCTSTR lpFilePath) {
		StreamFree();
		m_hStream = BASS_StreamCreateFile(FALSE, lpFilePath, 0, 0,
			BASS_IF_UNICODE);
		if(!m_hStream) m_hStream = BASS_APE_StreamCreateFile(FALSE, lpFilePath,
			0, 0, BASS_IF_UNICODE);
#if _WIN32
		if(!m_hStream) m_hStream = BASS_CD_StreamCreateFile((char*)lpFilePath,
			BASS_IF_UNICODE);
#endif
		if(!m_hStream) m_hStream = BASS_FLAC_StreamCreateFile(FALSE, lpFilePath,
			0, 0, BASS_IF_UNICODE);
#if _WIN32
		if(!m_hStream) m_hStream = BASS_AAC_StreamCreateFile(FALSE, lpFilePath,
			0, 0, BASS_IF_UNICODE);
		if(!m_hStream) m_hStream = BASS_MP4_StreamCreateFile(FALSE, lpFilePath,
			0, 0, BASS_IF_UNICODE);
		if(!m_hStream) m_hStream = BASS_ALAC_StreamCreateFile(FALSE, lpFilePath,
			0, 0, BASS_IF_UNICODE);
#endif
		return m_hStream ? TRUE : FALSE;
	}
	virtual void StreamFree() {
		if(m_hStream) BASS_StreamFree(m_hStream), m_hStream = 0;
	}

public: // メンバ変数

	HSTREAM m_hStream;
	HSYNC m_hSync;
};
//----------------------------------------------------------------------------

#endif