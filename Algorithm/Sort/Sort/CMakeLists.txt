# CMakeバージョン
cmake_minimum_required(VERSION 2.6)
# 静的ライブラリの作成
add_library(Sort STATIC
  sort.cpp
  sort_wrapper.cpp
)