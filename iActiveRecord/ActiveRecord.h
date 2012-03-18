#import <Foundation/Foundation.h>
#import "ARRelationships.h"
#import "ARValidations.h"
#import "ARValidatableProtocol.h"
#import "ARMigrationsHelper.h"

@interface ActiveRecord : NSObject
{
    NSNumber *id;
    NSMutableSet *errorMessages;
    NSMutableSet *changedFields;
@private
    BOOL isNew;
}

//@property (nonatomic, retain) NSMutableSet *errorMessages;
@property (nonatomic, retain) NSNumber *id;

#pragma mark - ObserveChanges
- (void)markAsNew;
- (void)didChangeField:(NSString *)aField;

#pragma mark - IgnoreFields

+ (void)initIgnoredFields;
+ (void)ignoreField:(NSString *)aField;

#pragma mark - validations

- (NSString *)recordName;


- (void)resetErrors;
- (void)addError:(NSString *)errMessage;
- (void)logErrors;


#pragma mark - Relationships

#pragma mark BelongsTo

- (id)belongsTo:(NSString *)aClassName;

#pragma mark HasMany

- (NSArray *)hasManyRecords:(NSString *)aClassName;
- (void)addRecord:(ActiveRecord *)aRecord;

#pragma mark HasManyThrough

- (NSArray *)hasMany:(NSString *)aClassName 
             through:(NSString *)aRelationsipClassName;
- (void)addRecord:(ActiveRecord *)aRecord 
          ofClass:(NSString *)aClassname 
          through:(NSString *)aRelationshipClassName;

#pragma mark - SQLQueries

+ (const char *)sqlOnCreate;
+ (const char *)sqlOnDeleteAll;
- (const char *)sqlOnSave;
- (const char *)sqlOnUpdate;

#pragma mark - Validations

+ (void)validateField:(NSString *)aField 
             asUnique:(BOOL)aUnique;
+ (void)validateField:(NSString *)aField 
           asPresence:(BOOL)aPresence;
- (BOOL)validateOnSave;
- (BOOL)validateOnUpdate;

- (BOOL)validateUniqueness;
- (BOOL)validatePresence;

- (BOOL)isValid;
- (BOOL)isValidUniquenessOfField:(NSString *)aField;
- (BOOL)isValidPresenceOfField:(NSString *)aField;

#pragma mark - Equal

- (BOOL)isEqualToRecord:(ActiveRecord *)anOtherRecord;

#pragma mark - 

+ (NSString *)tableName;
+ (id)newRecord;
+ (NSArray *)allRecords;

#pragma mark - Finders

+ (id)findById:(NSNumber *)anId;
+ (NSArray *)findWhereIdIn:(NSArray *)aValues;
+ (NSInteger)count;


- (BOOL)save;
- (BOOL)update;

@end
