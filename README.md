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
