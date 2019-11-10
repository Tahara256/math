# math

## 導入方法

1. submoduleとしてこのリポジトリを追加
```
$ git submodule add https://github.com/Tahara256/math.git
$ git submodule update --init --recursive
```

2. [math.vcxproj](/math.vcxproj)を自分のソリューションに追加

3. ランタイムライブラリを静的リンクする設定に変更  
このリポジトリの```property-sheets-vs-cpp```submoduleのプロパティシートを設定でも良い。

4. このリポジトリの[inc/](/inc/)ディレクトリをインクルードパスに追加

5. 自分のソリューションの```lib/$(PlatformTarget)/$(Configuration)/```をライブラリパスに追加  
e.g. ```lib/x64/Debug```

## 機能

- 二次元ベクトル
[Vector2](/inc/math/vector-2.h)
- 三次元ベクトル
[Vector3](/inc/math/vector-3.h")
- 四次元ベクトル
[Vector4](/inc/math/vector-4.h)

- 3x3行列
[Matrix3x3](/inc/math/matrix-3x3.h)
- 4x4行列
[Matrix4x4](/inc/math/matrix-4x4.h)

- 四元数
[Quaternion](inc/math/quaternion.h)

- 数学関数テンプレート
[FunctionTemplates](/inc/math/function-templates.h)
