//
//  NSObject+XTFMDB.h
//  demo_XTFMDB
//
//  Created by teason23 on 2017/5/8.
//  Copyright © 2017年 teaason. All rights reserved.
//
#define kPkid                          @"pkid"
#import <Foundation/Foundation.h>

@interface NSObject (XTFMDB)

@property (nonatomic) int       pkid ; // primaryKey
@property (nonatomic) long long xt_createTime ;
@property (nonatomic) long long xt_updateTime ;
@property (nonatomic) BOOL      xt_isDel ;

#pragma mark - tableIsExist

+ (BOOL)xt_tableIsExist ;
+ (BOOL)xt_autoCreateIfNotExist ;

#pragma mark - create

+ (BOOL)xt_createTable ;

#pragma mark - insert

// insert
- (BOOL)xt_insert ;
+ (BOOL)xt_insertList:(NSArray *)modelList ;

// insert or ignore
- (BOOL)xt_insertOrIgnore ;
+ (BOOL)xt_insertOrIgnoreWithList:(NSArray *)modelList ;

// insert or replace
- (BOOL)xt_insertOrReplace ;
+ (BOOL)xt_insertOrReplaceWithList:(NSArray *)modelList ;

// upsert
- (BOOL)xt_upsertWhereByProp:(NSString *)propName ;

#pragma mark - update

// update by pkid .
- (BOOL)xt_update ;// Update default update by pkid. if pkid nil, update by a unique prop if has .
+ (BOOL)xt_updateListByPkid:(NSArray *)modelList ;

// update by custom key . 
- (BOOL)xt_updateWhereByProp:(NSString *)propName ;
+ (BOOL)xt_updateList:(NSArray *)modelList
          whereByProp:(NSString *)propName ;

#pragma mark - select

+ (NSArray *)xt_selectAll ;
+ (NSArray *)xt_selectWhere:(NSString *)strWhere ; // param e.g. @" pkid = '1' "
+ (instancetype)xt_findFirstWhere:(NSString *)strWhere ;
+ (instancetype)xt_findFirst ;
+ (BOOL)xt_hasModelWhere:(NSString *)strWhere ;

// any sql execute Query
+ (NSArray *)xt_findWithSql:(NSString *)sql ;
+ (instancetype)xt_findFirstWithSql:(NSString *)sql ;

// func execute Statements
+ (id)xt_anyFuncWithSql:(NSString *)sql ;
+ (BOOL)xt_isEmptyTable ;
+ (int)xt_count ;
+ (int)xt_countWhere:(NSString *)whereStr ;
+ (double)xt_maxOf:(NSString *)property ;
+ (double)xt_maxOf:(NSString *)property where:(NSString *)whereStr ;
+ (double)xt_minOf:(NSString *)property ;
+ (double)xt_minOf:(NSString *)property where:(NSString *)whereStr ;
+ (double)xt_sumOf:(NSString *)property ;
+ (double)xt_sumOf:(NSString *)property where:(NSString *)whereStr ;
+ (double)xt_avgOf:(NSString *)property ;
+ (double)xt_avgOf:(NSString *)property where:(NSString *)whereStr ;

#pragma mark - delete

- (BOOL)xt_deleteModel ;
+ (BOOL)xt_deleteModelWhere:(NSString *)strWhere ; // param e.g. @" pkid = '1' "
+ (BOOL)xt_dropTable ;

#pragma mark - alter

+ (BOOL)xt_alterAddColumn:(NSString *)name
                     type:(NSString *)type ;
+ (BOOL)xt_alterRenameToNewTableName:(NSString *)name ;

#pragma mark - Constraints config

//props Sqlite Keywords
+ (NSDictionary *)modelPropertiesSqliteKeywords ; // set sqlite Constraints of property
// ignore Properties . these properties will not join db CURD .
+ (NSArray *)ignoreProperties ;
// Container property , value should be Class or Class name. Same as YYmodel .
+ (NSDictionary *)modelContainerPropertyGenericClass ;

@end
