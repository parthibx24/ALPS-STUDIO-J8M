////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2012 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (??MStar Confidential Information??) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

/**
 *
 * @file    mstar_drv_hotknot_queue.c
 *
 * @brief   This file defines the queue structure for hotknot
 *
 *
 */

////////////////////////////////////////////////////////////
/// Included Files
////////////////////////////////////////////////////////////
#include "mstar_drv_hotknot_queue.h"


#ifdef CONFIG_ENABLE_HOTKNOT
////////////////////////////////////////////////////////////
/// Data Types
////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
/// LOCAL VARIABLE DEFINITION
////////////////////////////////////////////////////////////
static unsigned char * _gQueue = NULL;
static unsigned short  _gQFront = 0;
static unsigned short  _gQRear;
static unsigned short  _gQSize = HOTKNOT_QUEUE_SIZE;


////////////////////////////////////////////////////////////
/// Macro
////////////////////////////////////////////////////////////
#define RESULT_OK                     0
#define RESULT_OVERPUSH              -1
#define RESULT_OVERPOP               -2


////////////////////////////////////////////////////////////
/// Function Prototypes
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
/// Function Implementation
////////////////////////////////////////////////////////////

void _DebugShowQueueArray(unsigned char *pBuf, unsigned short nLen)
{
    int i;

    for(i=0; i < nLen; i++)
    {
        DBG("%02X ", pBuf[i]);       

        if(i%16==15){  
            DBG("\n");
        }
    }
    DBG("\n");    
}


void CreateQueue()
{
    DBG("*** %s() ***\n", __func__);

	_gQueue = (unsigned char*)kmalloc(sizeof(unsigned char)*_gQSize, GFP_KERNEL );
    _gQFront = _gQRear = 0;
}


void ClearQueue()
{
    DBG("*** %s() ***\n", __func__);

    _gQFront = _gQRear = 0;
}


int PushQueue(unsigned char * pBuf, unsigned short nLength)
{
    unsigned short nPushLen = nLength;   

    DBG("*** %s() ***\n", __func__);

    //DBG("*** Show data to PushQueue() ***\n", __func__);
    //_DebugShowQueueArray(pBuf, nLength);
    //DBG("*** Show Queue data before PushQueue() ***\n", __func__);
    //_DebugShowQueueArray(_gQueue, _gQSize);
    
    DBG("*** Before PushQueue: _gQFront = %d, _gQRear = %d ***\n", _gQFront, _gQRear);

    if(_gQRear >= _gQFront)
    {
        if(nPushLen > 0 && _gQFront == 0 && _gQRear == _gQSize-1)    //full
        {
            DBG("*** PushQueue: RESULT_OVERPUSH ***\n");
            return RESULT_OVERPUSH;
        }
    
        if(nPushLen > _gQSize-1 - (_gQRear - _gQFront))    //over push
        {
            DBG("*** PushQueue: RESULT_OVERPUSH ***\n");        
            return RESULT_OVERPUSH;
        }
    
        if(_gQRear+nPushLen <= _gQSize-1)
        {
            memcpy(&_gQueue[_gQRear+1], pBuf, nPushLen);
            _gQRear = _gQRear + nPushLen;
        }
        else
        {
            unsigned short nQTmp = (_gQSize-1) -_gQRear;
            memcpy(&_gQueue[_gQRear+1], pBuf, nQTmp);          //push data from rear to end
            memcpy(_gQueue, &pBuf[nQTmp], nPushLen - nQTmp);    //push data lest
            _gQRear = nPushLen - nQTmp - 1;        
        }           
    }
    else    //_gQRear < _gQFront
    {
        if(nPushLen > 0 && _gQFront == _gQRear+1)    //full
        {
            DBG("*** PushQueue: RESULT_OVERPUSH ***\n");        
            return RESULT_OVERPUSH;
        }
    
        if(nPushLen > (_gQFront - _gQRear) - 1)    //over push
        {
            DBG("*** PushQueue: RESULT_OVERPUSH ***\n");        
            return RESULT_OVERPUSH;
        }
        
        memcpy(&_gQueue[_gQRear+1], pBuf, nPushLen);
        _gQRear = _gQRear + nPushLen;       
    }

    //DBG("*** Show Queue data after PushQueue() ***\n", __func__);
    //_DebugShowQueueArray(_gQueue, _gQSize);

    DBG("*** After PushQueue: _gQFront = %d, _gQRear = %d ***\n", _gQFront, _gQRear); 
    return nPushLen;     
}


int PopQueue(unsigned char * pBuf, unsigned short nLength)
{
    unsigned short nPopLen = nLength; 

    DBG("*** %s() ***\n", __func__);

    DBG("*** Before PopQueue: _gQFront = %d, _gQRear = %d ***\n", _gQFront, _gQRear);  

    if(_gQRear >= _gQFront)
    {
        if(nPopLen > 0 && _gQRear == _gQFront)    //empty
        {
            DBG("*** PushQueue: RESULT_OVERPOP ***\n");        
            return RESULT_OVERPOP;
        }
    
        if(nPopLen > _gQRear - _gQFront)    //over pop
        {
            DBG("*** PushQueue: RESULT_OVERPOP ***\n");        
            return RESULT_OVERPOP;
        }
        
        memcpy(pBuf, &_gQueue[_gQFront+1], nPopLen);
        _gQFront = _gQFront + nPopLen;
    }
    else    //_gQRear < _gQFront 
    {
        if(nPopLen > _gQSize - (_gQFront - _gQRear))    //over pop
        {
            DBG("*** PushQueue: RESULT_OVERPOP ***\n");        
            return RESULT_OVERPOP;
        }
    
        if(_gQFront + nPopLen <= _gQSize-1)
        {
            memcpy(pBuf, &_gQueue[_gQFront+1], nPopLen);
            _gQFront = _gQFront + nPopLen;
        }
        else
        {
            unsigned short nQTmp = (_gQSize-1) -_gQFront;
            memcpy(pBuf, &_gQueue[_gQFront+1], nQTmp);        //pop data from rear to end
            memcpy(&pBuf[nQTmp], _gQueue, nPopLen - nQTmp);    //pop data lest
            _gQFront = nPopLen - nQTmp - 1;        
        }
    }

    DBG("*** After PopQueue: _gQFront = %d, _gQRear = %d ***\n", _gQFront, _gQRear);   
    return nPopLen;    
}


int ShowQueue(unsigned char * pBuf, unsigned short nLength)    //just show data, not fetch data
{
    unsigned short nShowLen = nLength; 

    DBG("*** %s() ***\n", __func__);

    if(_gQRear >= _gQFront)
    {
        if(nShowLen > 0 && _gQRear == _gQFront)    //empty
        {
            return RESULT_OVERPOP;
        }
    
        if(nShowLen > _gQRear - _gQFront)    //over pop
        {
            return RESULT_OVERPOP;            
        }
        
        memcpy(pBuf, &_gQueue[_gQFront+1], nShowLen);
        //_gQFront = _gQFront + nPopLen;
    }
    else    //_gQRear < _gQFront 
    {
        if(nShowLen > _gQSize - (_gQFront - _gQRear))    //over pop
        {
            return RESULT_OVERPOP;            
        }
    
        if(_gQFront + nShowLen <= _gQSize-1)
        {
            memcpy(pBuf, &_gQueue[_gQFront+1], nShowLen);
            //_gQFront = _gQFront + nPopLen;
        }
        else
        {
            unsigned short nQTmp = (_gQSize-1) -_gQFront;
            memcpy(pBuf, &_gQueue[_gQFront+1], nQTmp);        //pop data from rear to end
            memcpy(&pBuf[nQTmp], _gQueue, nShowLen - nQTmp);    //pop data lest
            //_gQFront = nPopLen - nQTmp - 1;        
        }
    }
    
    return nShowLen;
}


void ShowAllQueue(unsigned char * pBuf, unsigned short * pFront, unsigned short * pRear)    //just show data, not fetch data
{
    DBG("*** %s() ***\n", __func__);

    memcpy(pBuf, _gQueue, HOTKNOT_QUEUE_SIZE);        //pop data from rear to end
    *pFront = _gQFront;
    *pRear = _gQRear;    
}


void DeleteQueue()
{
    DBG("*** %s() ***\n", __func__);

    _gQFront = _gQRear = 0;   
    
    if (_gQueue)
    {
        kfree(_gQueue);
        _gQueue = NULL;
    }
}

#endif //CONFIG_ENABLE_HOTKNOT