// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define DE_MAC_CIRC KC_GRV  // ^ (dead)
#define DE_MAC_1    KC_1    // 1
#define DE_MAC_2    KC_2    // 2
#define DE_MAC_3    KC_3    // 3
#define DE_MAC_4    KC_4    // 4
#define DE_MAC_5    KC_5    // 5
#define DE_MAC_6    KC_6    // 6
#define DE_MAC_7    KC_7    // 7
#define DE_MAC_8    KC_8    // 8
#define DE_MAC_9    KC_9    // 9
#define DE_MAC_0    KC_0    // 0
#define DE_MAC_SS   KC_MINS // ß
#define DE_MAC_ACUT KC_EQL  // ´ (dead)
#define DE_MAC_Q    KC_Q    // Q
#define DE_MAC_W    KC_W    // W
#define DE_MAC_E    KC_E    // E
#define DE_MAC_R    KC_R    // R
#define DE_MAC_T    KC_T    // T
#define DE_MAC_Z    KC_Y    // Z
#define DE_MAC_U    KC_U    // U
#define DE_MAC_I    KC_I    // I
#define DE_MAC_O    KC_O    // O
#define DE_MAC_P    KC_P    // P
#define DE_MAC_UDIA KC_LBRC // Ü
#define DE_MAC_PLUS KC_RBRC // +
#define DE_MAC_A    KC_A    // A
#define DE_MAC_S    KC_S    // S
#define DE_MAC_D    KC_D    // D
#define DE_MAC_F    KC_F    // F
#define DE_MAC_G    KC_G    // G
#define DE_MAC_H    KC_H    // H
#define DE_MAC_J    KC_J    // J
#define DE_MAC_K    KC_K    // K
#define DE_MAC_L    KC_L    // L
#define DE_MAC_ODIA KC_SCLN // Ö
#define DE_MAC_ADIA KC_QUOT // Ä
#define DE_MAC_HASH KC_NUHS // #
#define DE_MAC_LABK KC_NUBS // <
#define DE_MAC_Y    KC_Z    // Y
#define DE_MAC_X    KC_X    // X
#define DE_MAC_C    KC_C    // C
#define DE_MAC_V    KC_V    // V
#define DE_MAC_B    KC_B    // B
#define DE_MAC_N    KC_N    // N
#define DE_MAC_M    KC_M    // M
#define DE_MAC_COMM KC_COMM // ,
#define DE_MAC_DOT  KC_DOT  // .
#define DE_MAC_MINS KC_SLSH // -
#define DE_MAC_DEG  S(DE_MAC_CIRC) // °
#define DE_MAC_EXLM S(DE_MAC_1)    // !
#define DE_MAC_DQUO S(DE_MAC_2)    // "
#define DE_MAC_SECT S(DE_MAC_3)    // §
#define DE_MAC_DLR  S(DE_MAC_4)    // $
#define DE_MAC_PERC S(DE_MAC_5)    // %
#define DE_MAC_AMPR S(DE_MAC_6)    // &
#define DE_MAC_SLSH S(DE_MAC_7)    // /
#define DE_MAC_LPRN S(DE_MAC_8)    // (
#define DE_MAC_RPRN S(DE_MAC_9)    // )
#define DE_MAC_EQL  S(DE_MAC_0)    // =
#define DE_MAC_QUES S(DE_MAC_SS)   // ?
#define DE_MAC_GRV  S(DE_MAC_ACUT) // ` (dead)
#define DE_MAC_ASTR S(DE_MAC_PLUS) // *
#define DE_MAC_QUOT S(DE_MAC_HASH) // '
#define DE_MAC_RABK S(DE_MAC_LABK) // >
#define DE_MAC_SCLN S(DE_MAC_COMM) // ;
#define DE_MAC_COLN S(DE_MAC_DOT)  // :
#define DE_MAC_UNDS S(DE_MAC_MINS) // _
#define DE_MAC_DLQU A(DE_MAC_CIRC) // „
#define DE_MAC_IEXL A(DE_MAC_1)    // ¡
#define DE_MAC_LDQU A(DE_MAC_2)    // “
#define DE_MAC_PILC A(DE_MAC_3)    // ¶
#define DE_MAC_CENT A(DE_MAC_4)    // ¢
#define DE_MAC_LBRC A(DE_MAC_5)    // [
#define DE_MAC_RBRC A(DE_MAC_6)    // ]
#define DE_MAC_PIPE A(DE_MAC_7)    // |
#define DE_MAC_LCBR A(DE_MAC_8)    // {
#define DE_MAC_RCBR A(DE_MAC_9)    // }
#define DE_MAC_NEQL A(DE_MAC_0)    // ≠
#define DE_MAC_IQUE A(DE_MAC_SS)   // ¿
#define DE_MAC_LDAQ A(DE_MAC_Q)    // «
#define DE_MAC_NARS A(DE_MAC_W)    // ∑
#define DE_MAC_EURO A(DE_MAC_E)    // €
#define DE_MAC_REGD A(DE_MAC_R)    // ®
#define DE_MAC_DAGG A(DE_MAC_T)    // †
#define DE_MAC_OMEG A(DE_MAC_Z)    // Ω
#define DE_MAC_DIAE A(DE_MAC_U)    // ¨ (dead)
#define DE_MAC_FRSL A(DE_MAC_I)    // ⁄
#define DE_MAC_OSTR A(DE_MAC_O)    // Ø
#define DE_MAC_PI   A(DE_MAC_P)    // π
#define DE_MAC_BULT A(DE_MAC_UDIA) // •
#define DE_MAC_PLMN A(DE_MAC_PLUS) // ±
#define DE_MAC_ARNG A(DE_MAC_A)    // Å
#define DE_MAC_SLQU A(DE_MAC_S)    // ‚
#define DE_MAC_PDIF A(DE_MAC_D)    // ∂
#define DE_MAC_FHK  A(DE_MAC_F)    // ƒ
#define DE_MAC_COPY A(DE_MAC_G)    // ©
#define DE_MAC_FORD A(DE_MAC_H)    // ª
#define DE_MAC_MORD A(DE_MAC_J)    // º
#define DE_MAC_INCR A(DE_MAC_K)    // ∆
#define DE_MAC_AT   A(DE_MAC_L)    // @
#define DE_MAC_OE   A(DE_MAC_ODIA) // Œ
#define DE_MAC_AE   A(DE_MAC_ADIA) // Æ
#define DE_MAC_LSQU A(DE_MAC_HASH) // ‘
#define DE_MAC_LTEQ A(DE_MAC_LABK) // ≤
#define DE_MAC_YEN  A(DE_MAC_Y)    // ¥
#define DE_MAC_AEQL A(DE_MAC_X)    // ≈
#define DE_MAC_CCCE A(DE_MAC_C)    // Ç
#define DE_MAC_SQRT A(DE_MAC_V)    // √
#define DE_MAC_INTG A(DE_MAC_B)    // ∫
#define DE_MAC_TILD A(DE_MAC_N)    // ~ (dead)
#define DE_MAC_MICR A(DE_MAC_M)    // µ
#define DE_MAC_INFN A(DE_MAC_COMM) // ∞
#define DE_MAC_ELLP A(DE_MAC_DOT)  // …
#define DE_MAC_NDSH A(DE_MAC_MINS) // –
#define DE_MAC_NOT  S(A(DE_MAC_1))    // ¬
#define DE_MAC_RDQU S(A(DE_MAC_2))    // ”
#define DE_MAC_PND  S(A(DE_MAC_4))    // £
#define DE_MAC_FI   S(A(DE_MAC_5))    // ﬁ
#define DE_MAC_BSLS S(A(DE_MAC_7))    // (backslash)
#define DE_MAC_STIL S(A(DE_MAC_8))    // ˜
#define DE_MAC_MDDT S(A(DE_MAC_9))    // ·
#define DE_MAC_MACR S(A(DE_MAC_0))    // ¯
#define DE_MAC_DOTA S(A(DE_MAC_SS))   // ˙
#define DE_MAC_RNGA S(A(DE_MAC_ACUT)) // ˚
#define DE_MAC_RDAQ S(A(DE_MAC_Q))    // »
#define DE_MAC_PERM S(A(DE_MAC_E))    // ‰
#define DE_MAC_CEDL S(A(DE_MAC_R))    // ¸
#define DE_MAC_DACU S(A(DE_MAC_T))    // ˝
#define DE_MAC_CARN S(A(DE_MAC_Z))    // ˇ
#define DE_MAC_AACU S(A(DE_MAC_U))    // Á
#define DE_MAC_UCIR S(A(DE_MAC_I))    // Û
#define DE_MAC_NARP S(A(DE_MAC_P))    // ∏
#define DE_MAC_APPL S(A(DE_MAC_PLUS)) //  (Apple logo)
#define DE_MAC_IACU S(A(DE_MAC_S))    // Í
#define DE_MAC_TM   S(A(DE_MAC_D))    // ™
#define DE_MAC_IDIA S(A(DE_MAC_F))    // Ï
#define DE_MAC_IGRV S(A(DE_MAC_G))    // Ì
#define DE_MAC_OACU S(A(DE_MAC_H))    // Ó
#define DE_MAC_DLSI S(A(DE_MAC_J))    // ı
#define DE_MAC_FL   S(A(DE_MAC_L))    // ﬂ
#define DE_MAC_GTEQ S(A(DE_MAC_LABK)) // ≥
#define DE_MAC_DDAG S(A(DE_MAC_Y))    // ‡
#define DE_MAC_UGRV S(A(DE_MAC_X))    // Ù
#define DE_MAC_LOZN S(A(DE_MAC_V))    // ◊
#define DE_MAC_LSAQ S(A(DE_MAC_B))    // ‹
#define DE_MAC_RSAQ S(A(DE_MAC_N))    // ›
#define DE_MAC_BREV S(A(DE_MAC_M))    // ˘
#define DE_MAC_OGON S(A(DE_MAC_COMM)) // ˛
#define DE_MAC_DIV  S(A(DE_MAC_DOT))  // ÷
#define DE_MAC_MDSH S(A(DE_MAC_MINS)) // —
