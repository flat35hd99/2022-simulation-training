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
