# As Library <a href="http://creativecommons.org/publicdomain/zero/1.0/deed.ja"><img src="https://img.shields.io/badge/license-CC0-blue.svg"></a> <a href="https://github.com/Kasugaccho/AsLib"><img src="https://img.shields.io/badge/0.4.0.0%20%CE%B1-passing-brightgreen.svg"></a>
当ライブラリはC++でのマルチプラットフォーム開発をサポートします。
[![AsLib](https://raw.githubusercontent.com/Kasugaccho/AsLib/master/aslib/Picture/Title/aslib150.png "AsLib")](https://github.com/Kasugaccho/AsLib)

当ライブラリで開発した作品はopenFrameworksやOpenSiv3D等の
多岐に渡るC++(GUI)ライブラリで実行することが出来ます。

## License

These codes are licensed under CC0.

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)

当ライブラリは、他のGUIライブラリと組み合わせて使うことを前提としていますので、
組み合わせる際は、他のライブラリのライセンスをご確認の上、ご使用ください。

## ゲームエンジン等の対応度

| エンジン名 | 2文字略称 | 対応バージョン | 種類 |
|:---:|:---:|:---:|:---:|
| Default | TP | None | Library |
| openFrameworks | OF | 0.10.0 | Framework |
| DxLib | DL | 3.19b | Library |
| OpenSiv3D | S3 | 0.2.7 | Library |
| Cocos2d-x | C2 | 3.17 | Framework |
| SFML | SF | 2.5.0 | Library |

| 機能 | ヘッダー | TP | OF | DL | S3 | C2 | SF |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| ライブラリ | Lib | ◎ | 〇 | ◎ | ◎ | 〇 | × |
| タッチ入力 | Touch | × | × | 〇 | ▲ | × | × |
| マウス入力 | Mouse | × | 〇 | 〇 | 〇 | × | × |
| キーボード入力 | Key | × | × | 〇 | 〇 | × | × |
| ゲームパッド入力 | GamePad | × | × | × | × | × | × |
| 文字入力 | KeyInput | × | × | 〇 | × | × | × |
| 画像表示 | AsTexture | × | 〇 | 〇 | 〇 | × | × |
| 音声 | Sound | × | × | 〇 | 〇 | × | × |
| フォント文字表示 | Font | × | ▲ | 〇 | 〇 | × | × |
| 四角形描画 | Rect | × | 〇 | 〇 | 〇 | × | × |
| 円形描画 | Circle | × | 〇 | 〇 | 〇 | × | × |
| 専用読み書き | AsFile | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| バッテリー | Battery | × | × | 〇 | 〇 | × | × |
| メイン情報クラス | Class | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| 色クラス | Color | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| 位置クラス | Struct | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| 定数変数 | Const | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| マウスカウンター | Counter | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| ファイル読み書き | File | ◎ | ◎ | ◎ | ◎ | ◎ | ◎ |
| ライセンス | License | ◎ | 〇 | ◎ | ◎ | × | × |
| メインループ | Loop | × | × | 〇 | 〇 | × | × |
| 2Dマップ | Map | 〇 | 〇 | 〇 | 〇 | 〇 | 〇 |
| 乱数 | Rand | 〇 | 〇 | 〇 | 〇 | 〇 | 〇 |
| SNS | SNS | × | × | 〇 | 〇 | × | × |
| 初期化・基本処理 | Std | 〇 | ▲ | 〇 | 〇 | × | × |
| ウェイト | Stop | × | × | 〇 | ▲ | × | × |
| 変数型 | Type | 〇 | 〇 | 〇 | 〇 | × | × |
| Wi-Fi | WiFi | × | × | ▲ | ▲ | × | × |
| エフェクト | Effect | ▲ | ▲ | ▲ | ▲ | × | × |
| UTF | UTF | 〇 | 〇 | 〇 | 〇 | 〇 | 〇 |
| 管理クラス | MainControl | ▲ | ▲ | ▲ | ▲ | × | × |
|  |  |  |  |  |  |  |  |
