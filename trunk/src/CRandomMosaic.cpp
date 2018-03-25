// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

/************************************************************************************

    Copyright (C) 2000-2002, 2007 Thibaut Tollemer

    This file is part of Bombermaaan.

    Bombermaaan is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bombermaaan is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Bombermaaan.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************************/


/**
 *  \file CRandomMosaic.cpp
 *  \brief A random mosaic
 */

#include "StdAfx.h"
#include "CRandomMosaic.h"
#include "CMosaic.h"

//******************************************************************************************************************************
//******************************************************************************************************************************
//******************************************************************************************************************************

SMosaicTileProperties CRandomMosaic::m_MosaicTileProperties [3][3] =
{
    {
        { 46, 0, 9, 12, 82, 41 },
        { 47, 0, 7, 12, 82, 41 },
        { 48, 0, 7, 12, 82, 41 }
    },
    
    {
        { 19, 0, 9, 12, 82, 41 },
        { 51, 0, 7, 12, 82, 41 },
        { 52, 0, 7, 12, 82, 41 }
    },
    
    {
        { 29, 0, 9, 12, 82, 41 },
        { 49, 0, 7, 12, 82, 41 },
        { 50, 0, 7, 12, 82, 41 }
    }

};

//******************************************************************************************************************************
//******************************************************************************************************************************
//******************************************************************************************************************************

CMosaic* CRandomMosaic::CreateRandomMosaic (CDisplay* pDisplay, 
                                            int SpriteLayer, 
                                            int PriorityInLayer, 
                                            float SpeedX, 
                                            float SpeedY, 
                                            EMosaicColor Color)
{
    SMosaicTileProperties* pMosaicTileProperties = &m_MosaicTileProperties[(int)Color][RANDOM(3)];    

    CMosaic* pNewMosaic = new CMosaic;
    
    pNewMosaic->SetDisplay (pDisplay);
    pNewMosaic->Create (pMosaicTileProperties->SpriteTable, 
                        pMosaicTileProperties->Sprite, 
                        SpriteLayer, 
                        PriorityInLayer, 
                        pMosaicTileProperties->Width, 
                        pMosaicTileProperties->Height, 
                        pMosaicTileProperties->CountX, 
                        pMosaicTileProperties->CountY, 
                        SpeedX,
                        SpeedY);

    return pNewMosaic;
}

//******************************************************************************************************************************
//******************************************************************************************************************************
//******************************************************************************************************************************
