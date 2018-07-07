# As Library
当ライブラリはC++でのマルチプラットフォーム開発をサポートします。

## License

These codes are licensed under CC0.

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)

当ライブラリは、他のゲームエンジンと組み合わせて使うことを前提としていますので、
組み合わせる際は、他のライブラリのライセンスをご確認の上、ご使用ください。

## ゲームエンジン等の対応度

| エンジン名 | 2文字略称 | 対応バージョン |
|:---:|:---:|:---:|
| Default | TP | None |
| openFrameworks | OF | 0.10.0 |
| DxLib | DL | 3.19b |
| OpenSiv3D | S3 | 0.2.7 |

| 機能 | ヘッダー | TP | OF | DL | S3 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| ライブラリ | Lib | ◎ | ▲ | ◎ | ◎ |
| タッチ入力 | Touch | × | × | 〇 | ▲ |
| マウス入力 | Mouse | × | × | 〇 | 〇 |
| キーボード入力 | Key | × | × | 〇 | ▲ |
| ゲームパッド入力 | GamePad | × | × | × | × |
| 文字入力 | KeyInput | × | × | 〇 | × |
| 画像表示 | Texture | × | × | 〇 | 〇 |
| 連番画像表示 | Texture | × | × | 〇 | 〇 |
| フォント文字表示 | Font | × | × | 〇 | 〇 |
| 四角形描画 | Rect | × | × | 〇 | 〇 |
| 円形描画 | Circle | × | × | 〇 | 〇 |
| 専用読み書き | AsFile | ◎ | ◎ | ◎ | ◎ |
| バッテリー | Battery | × | × | 〇 | 〇 |
| メイン情報クラス | Class | ◎ | × | ◎ | ◎ |
| 色クラス | Color | ◎ | ▲ | ◎ | ◎ |
| 位置クラス | Struct | ◎ | ▲ | ◎ | ◎ |
| 定数変数 | Const | ◎ | 〇 | ◎ | ◎ |
| マウスカウンター | Counter | ◎ | ▲ | ◎ | ◎ |
| ファイル読み書き | File | ◎ | ◎ | ◎ | ◎ |
| ライセンス | License | ▲ | ▲ | ▲ | ▲ |
| メインループ | Loop | 〇 | × | 〇 | 〇 |
| 2Dマップ | Map | 〇 | ▲ | 〇 | 〇 |
| 乱数 | Rand | 〇 | 〇 | 〇 | 〇 |
| SNS | SNS | × | × | 〇 | 〇 |
| 初期化・基本処理 | Std | 〇 | ▲ | 〇 | 〇 |
| ウェイト | Stop | × | × | 〇 | ▲ |
| 変数型 | Type | 〇 | ▲ | 〇 | 〇 |
| Wi-Fi | WiFi | × | × | ▲ | ▲ |
| 管理クラス | MainControl | ▲ | ▲ | ▲ | ▲ |
|  |  |  |  |  |  |


・ゲームエンジン無し(Console)
画像・音声出力等は無し。

・openFrameworks
現在のバージョンでは初歩的な動作のみ対応済み。

・ＤＸライブラリ
現在のバージョンでは基本的な動作のみ対応済み。

・OpenSiv3D
現在のバージョンでは基本的な動作のみ対応済み。

・Qt
現在は対応予定無し。

・Cocos2d-x
現在は対応予定無し。

・Unreal Engine
現在は対応予定無し。

・SDL
現在は対応予定無し。

・Siv3D
現在は対応予定無し。

・Cinder
現在は対応予定無し。

・SFML
現在は対応予定無し。

・Irrlicht Engine
現在は対応予定無し。

## 開発者募集中

開発に興味を持った方は、
wanotaitei@gmail.com
または、
Twitter: @wanotaitei
まで返事をください。
