cmake_minimum_required (VERSION 2.6)

#---------------------------------------------------
# コンパイル時のオプションの設定
#---------------------------------------------------
# リリースビルド用オプション
set(CMAKE_CPP_FLAGS_TELEASE "-Wall -O2")
# デバッグビルド用オプション
set(CMAKE_CPP_FLAGS_DEBUG "-g -O0")
# ビルドタイプ（下記の場合、Release）
set(CMAKE_BUILD_TYPE Release)
#----------------------------------------------------

# プロジェクト名
project(P1-1)

# Mainビルド
add_executable (main main.cpp)

# 出力先の設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../) 

# ターゲットリンクライブラリ
target_link_libraries(main m)