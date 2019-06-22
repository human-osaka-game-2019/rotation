# プロジェクト構成
## RotateVerticesAroundOrigin
DirectXでのサンプルです。  
原点(2Dなのでウィンドウの左上部分)を中心に画像がクルクル回ります。

|キー種別|動作|
|---|---|
|Lキー|左上隅を中心に左回転|
|Rキー|左上隅を中心に右回転|
|←キー|象の左上隅が象から見て後方に移動|
|↑キー|象の左上隅が象から見て上方に移動|
|→キー|象の左上隅が象から見て前方に移動|
|↓キー|象の左上隅が象から見て下方に移動|

## RotateVertices
DirectXを用いたサンプルです。  
画像がその場でクルクル回ります。
処理としては、
1. 左上で矩形を回転させ
2. それを元の位置に平行移動させて戻す

を毎フレームやることで、あたかもその場で回っているように見せています。

|キー種別|動作|
|---|---|
|Lキー|その場で左回転|
|Rキー|その場で右回転|
|←キー|象の中心点が画面左方向に移動|
|↑キー|象の中心点が画面上方向に移動|
|→キー|象の中心点が画面右方向に移動|
|↓キー|象の中心点が画面下方向に移動|

## RotateArray
配列の回転のサンプルです。  
コンソール画面でテトリスのZブロックが左右にクルクル回ります。

# 基本の考え
結局のところ数学の話です。  
下図のように、ある点`(x, y)`を`θ`回転させた点`(x', y')`について考えます。

![top-page](https://raw.githubusercontent.com/human-osaka-game-2019/rotation/images/回転.png)

※前提として、加法定理は知っているものとします。
```
sin(α + β) = sinα・cosβ + cosα・sinβ
cos(α + β) = cosα・cosβ - sinα・sinβ
```

以下、回転後の点`(x', y')`のx座標とy座標はそれぞれどのような式で導けるのかをゴリゴリ証明していきます。

(証明スタート)  
元の点`(x, y)`がX軸となす角を`α`とし、原点`O`からの距離を`r`とすると
```
cosα = x / r
sinα = y / r
```
となり、それぞれを変形すると
```
x = r・cosα
y = r・sinα
```
となる。

点`(x', y')`についても同様に考えると
```
cos(α + θ) = x' / r
sin(α + θ) = y' / r
```
となり、これを変形すると
```
x' = r・cos(α + θ)
y' = r・sin(α + θ)
```
と表せる。

ここで、加法定理より
```
x' = r・(cosα・cosθ - sinα・sinθ)
```
また、
```
sinα = y / r
cosα = x / r
```
なので
```
x' = r・(x/r・cosθ - y/r・sinθ)
   = x・cosθ - y・sinθ
```
同様に
```
y' = r・(sinα・cosθ + cosα・sinθ)
   = r・(y/r・cosθ + x/r・sinθ)
   = y・cosθ + x・sinθ
```
となる。

纏めると、
```
x' = x・cosθ - y・sinθ
y' = x・sinθ + y・cosθ 
```
(証明おわり)

## 90度回転について
前述の
```
x' = x・cosθ - y・sinθ
y' = x・sinθ + y・cosθ 
```
に
```
sin90° = 1
cos90° = 0
```
を当て嵌めると、点`(x, y)`を90°回転した点は`(-y, x)`となることがわかります。  

同様に
```
sin(-90°) = -1
cos(-90°) = 0
```
を当て嵌めると、点`(x, y)`を-90°回転した点は`(y, -x)`となりますね。

ここまでの話は(通常の数学の話として)Y軸の正方向は上向きで説明してきましたが、2DのゲームではY軸の正方向は下向きです。つまり、下に行くほどY座標の値が大きくなります。  
従って、**回転角の正負が通常の数学と逆**になる点にご注意下さい。  
90°回転は右回り、-90°回転は左回りになります。
