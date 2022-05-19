# 最適化と実行速度比較

## ファイル説明

- `if.cpp`
  - floor関数の代わりにif文を使うもの
- `original.cpp`
  - floor関数を使うもの。ただし周期境界条件に関するバグ修正したもの。
  
## テスト方法

```console
make
cd tmp_o3
for name in "if" "original";do for i in `seq 0 2`;do (time ../${name}.out) 2> ${name}_${i}.time;done;done;
```

## 結果

2つの実行結果は有意な差は示さなかった。

## 補足

CPUはIntel(R) Xeon(R) Gold 6248 CPU @ 2.50GHz

コンパイラは
```console
$ g++ --version
g++ (GCC) 4.8.5 20150623 (Red Hat 4.8.5-39)
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE
```

OSは

```console
$ cat /etc/os-release 
NAME="Red Hat Enterprise Linux Server"
VERSION="7.7 (Maipo)"
ID="rhel"
ID_LIKE="fedora"
VARIANT="Server"
VARIANT_ID="server"
VERSION_ID="7.7"
PRETTY_NAME="Red Hat Enterprise Linux"
ANSI_COLOR="0;31"
CPE_NAME="cpe:/o:redhat:enterprise_linux:7.7:GA:server"
HOME_URL="https://www.redhat.com/"
BUG_REPORT_URL="https://bugzilla.redhat.com/"

REDHAT_BUGZILLA_PRODUCT="Red Hat Enterprise Linux 7"
REDHAT_BUGZILLA_PRODUCT_VERSION=7.7
REDHAT_SUPPORT_PRODUCT="Red Hat Enterprise Linux"
REDHAT_SUPPORT_PRODUCT_VERSION="7.7"
```

## メモ

もともとのコードは、周期境界条件の中に戻す処理を、プリサンプリングの段階ではやっていなかった。(`p_boundary()`の呼び出しがない)そのため、本計算で`floor()`を`if`に取り替えて実装すると、箱の長さの半分の2倍より外にある粒子を箱の中に戻すことができず、バグを生んでしまう。注意が必要（一敗）