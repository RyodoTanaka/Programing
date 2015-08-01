# CMakeバージョン
cmake_minimum_required(VERSION 2.6)
# 静的ライブラリの作成
add_library(Sort STATIC
  sort_wrapper.cpp
  sort.cpp
)