#import "XADArchiveParser.h"

@interface XAD7ZipParser:XADArchiveParser
{
	NSDictionary *mainstreams;

	NSDictionary *currfolder;
	CSHandle *currfolderhandle;
}

+(int)requiredHeaderSize;
+(BOOL)recognizeFileWithHandle:(CSHandle *)handle firstBytes:(NSData *)data name:(NSString *)name;
+(XADRegex *)volumeRegexForFilename:(NSString *)filename;
+(BOOL)isFirstVolume:(NSString *)filename;

-(id)initWithHandle:(CSHandle *)handle name:(NSString *)name;
-(void)dealloc;

-(void)parse;

-(NSArray *)parseFilesForHandle:(CSHandle *)handle;

-(void)parseBitVectorForHandle:(CSHandle *)handle array:(NSArray *)array key:(NSString *)key;
-(NSIndexSet *)parseDefintionVectorForHandle:(CSHandle *)handle numberOfElements:(int)num;
-(void)parseDatesForHandle:(CSHandle *)handle array:(NSMutableArray *)array key:(NSString *)key;
-(void)parseCRCsForHandle:(CSHandle *)handle array:(NSMutableArray *)array;
-(void)parseNamesForHandle:(CSHandle *)handle array:(NSMutableArray *)array;
-(void)parseAttributesForHandle:(CSHandle *)handle array:(NSMutableArray *)array;

-(NSDictionary *)parseStreamsForHandle:(CSHandle *)handle;
-(NSArray *)parsePackedStreamsForHandle:(CSHandle *)handle;
-(NSArray *)parseFoldersForHandle:(CSHandle *)handle packedStreams:(NSArray *)packedstreams;
-(void)parseFolderForHandle:(CSHandle *)handle dictionary:(NSMutableDictionary *)dictionary
packedStreams:(NSArray *)packedstreams packedStreamIndex:(int *)packedstreamindex;
-(void)parseSubStreamsInfoForHandle:(CSHandle *)handle folders:(NSArray *)folders;
-(void)setupDefaultSubStreamsForFolders:(NSArray *)folders;
-(NSArray *)collectAllSubStreamsFromFolders:(NSArray *)folders;

-(CSHandle *)handleForEntryWithDictionary:(NSDictionary *)dict wantChecksum:(BOOL)checksum;
-(CSHandle *)handleForStreams:(NSDictionary *)streams substreamIndex:(int)substreamindex wantChecksum:(BOOL)checksum;
-(CSHandle *)outHandleForFolder:(NSDictionary *)folder index:(int)index;
-(CSHandle *)inHandleForFolder:(NSDictionary *)folder coder:(NSDictionary *)coder index:(int)index;
-(CSHandle *)inHandleForFolder:(NSDictionary *)folder index:(int)index;

-(NSString *)formatName;

@end