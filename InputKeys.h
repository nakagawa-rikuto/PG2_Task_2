﻿#pragma once

//=======================================
// キー入力の変数を持つ構造体
//=======================================

/*
この構造体をキー入力が欲しい処理に引数に入れることで
keys,preKeysのように二つの引数を入れるのではなく
構造体でひとつの引数にまとめることができる
*/

struct InputKeys {
	char keys[256];
	char preKeys[256];
};
