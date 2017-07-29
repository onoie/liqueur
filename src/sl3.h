//
// Created by onoie on 7/29/17.
//
//quote http://qiita.com/Ki4mTaria/items/bce1a6080e537fb1c949
#ifndef LIQUEUR_SL3_H
#define LIQUEUR_SL3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
int print_resp( void * , int , char ** , char ** );

int sl3(const char *filename){
    int ret       = 0;
    sqlite3 *conn = NULL;
    char *err_msg = NULL;
    char sql_str[255];
    memset( &sql_str[0] , 0x00 , sizeof(sql_str) );

    // アクセス
    ret = sqlite3_open(
            filename, // DBファイル名
            &conn                 // DBコネクション
    );
    if( SQLITE_OK != ret ){
        // error
        return EXIT_FAILURE;
    }

    // SQL文発行
    snprintf( &sql_str[0] , sizeof(sql_str)-1 , "select * from tb_test" );
    ret = sqlite3_exec(
            conn        , // DBコネクション
            &sql_str[0] , // SQL文
            print_resp  , // コールバック関数
            NULL        , // CB関数に渡す引数
            &err_msg      // エラーメッセージ
    );
    if( SQLITE_OK != ret ){
        // error
        sqlite3_close( conn );
        sqlite3_free( err_msg );
        return EXIT_FAILURE;
    }

    // 後片づけ
    ret = sqlite3_close( conn );
    if( SQLITE_OK != ret ){
        // error
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int print_resp(
        void *get_prm   , // sqlite3_exec()の第4引数
        int col_cnt     , // 列数
        char **row_txt  , // 行内容
        char **col_name   // 列名
){
    printf( "\n%s : %s" , row_txt[0] , row_txt[1] );
    return 0;
}

#endif //LIQUEUR_SL3_H
