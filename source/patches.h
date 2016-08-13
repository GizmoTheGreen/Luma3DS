/*
*   This file is part of Luma3DS
*   Copyright (C) 2016 Aurora Wright, TuxSH
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b of GPLv3 applies to this file: Requiring preservation of specified
*   reasonable legal notices or author attributions in that material or in the Appropriate Legal
*   Notices displayed by works containing it.
*/

#pragma once

#include "types.h"

typedef struct patchData {
    u32 offset[2];
    union {
        u8 type0[8];
        u16 type1;
    } patch;
    u32 type;
} patchData;

extern bool isN3DS;

u8 *getProcess9(u8 *pos, u32 size, u32 *process9Size, u32 *process9MemAddr);
u32* getInfoForArm11ExceptionHandlers(u8 *pos, u32 size, u32 *stackAddr, u32 *codeSetOffset);
void patchSignatureChecks(u8 *pos, u32 size);
void patchTitleInstallMinVersionCheck(u8 *pos, u32 size);
void patchFirmlaunches(u8 *pos, u32 size, u32 process9MemAddr);
void patchFirmWrites(u8 *pos, u32 size);
void patchFirmWriteSafe(u8 *pos, u32 size);
void patchExceptionHandlersInstall(u8 *pos, u32 size);
void patchSvcBreak9(u8 *pos, u32 size, u32 k9addr);
void patchSvcBreak11(u8 *pos, u32 size);
void patchKernel9Panic(u8 *pos, u32 size, FirmwareType firmType);
void patchKernel11Panic(u8 *pos, u32 size);
void patchArm11SvcAccessChecks(u8 *pos, u32 size);
void patchK11ModuleChecks(u8 *pos, u32 size);
void patchP9AccessChecks(u8 *pos, u32 size);
void patchUnitInfoValueSet(u8 *pos, u32 size);
void reimplementSvcBackdoor(u8 *pos, u32 size);
void applyLegacyFirmPatches(u8 *pos, FirmwareType firmType);
u8 *getUnitInfoValueSet(u8 *pos, u32 size);
