# Arduino SPI and Serial TEST

Arduinoを用いてよい感じでシリアル通信とSPI通信をしたい！

## Serial_test

シリアル通信でechoを行うっぽい。

### How to use

1. Arduinoに書き込む（Unoとnano(old)で確認、多分何でもいける）
1. シリアル通信する
    - `0`を受けると13番ピン（ledpinで指定、内蔵LEDだと楽）のLEDが点灯する
    - `0`以外を受けると13番ピンのLEDが消灯する
    - シリアルモニタには送信した値を2進数に変換してテキスト化（ASCIIコード化）されたものと送った生のデータが返ってくる
    - 送信せずに5秒**くらい**ほっておくと最後に送ったデータが返ってくる

26行目くらいのやつのコメントアウトを外すと5秒**くらい**毎にLEDが消えると思います。

**`0`はASCIIコードの0ではないです**

**Arduino付属のシリアルモニタはテキストとして送るので使えません。適切なシリアル通信ソフトを使ってください。**

## SPI_test

SPI通信でMCP23S17というIOエキスパンダを制御してみる（outだけ）

### How to use

1. Arduinoに書き込む（Unoで確認）
    - [n0mjs710/MCP23S17: Arduino Driver for Microchip MCP23S17](https://github.com/n0mjs710/MCP23S17)のライブラリを使ってるので適切な方法で導入のこと
1. 適切な回路を組む（この項は準備中）
    - [Arduino Playground \- MCP23S17 Class for Arduino](https://playground.arduino.cc/Main/MCP23S17#Introduction)
    - [n0mjs710/MCP23S17: Arduino Driver for Microchip MCP23S17](https://github.com/n0mjs710/MCP23S17)
1. 光ったりします
    - なんかウェーブっぽい感じでLチカします

## SPI_Serial_TEST

シリアル通信でMCP23S17を制御する。

### How to use

1. Arduinoに書き込む（Unoで確認）
1. `SPI_test`と同じ回路を組む
1. シリアル通信をする