#include "al2o3_lz4/lz4.h"
#include "lib/lz4.h"
#include "lib/lz4hc.h"
#include "lib/xxhash.h"

AL2O3_EXTERN_C int LZ4_Compress(uint8_t const* src, uint8_t* dst, size_t srcSize, size_t dstCapacity) {
	return LZ4_compress_default(src, dst, (int)srcSize, (int)dstCapacity);
}
AL2O3_EXTERN_C int LZ4_CompressHigh (uint8_t const* src, uint8_t * dst, size_t srcSize, size_t dstCapacity, int compressionLevel) {
	return LZ4_compress_HC(src, dst, (int)srcSize, (int)dstCapacity, compressionLevel );
}
AL2O3_EXTERN_C int LZ4_Decompress(uint8_t const* src, uint8_t* dst, size_t compressedSize, size_t dstCapacity) {
	return LZ4_decompress_safe(src, dst, (int)compressedSize, (int)dstCapacity);
}
AL2O3_EXTERN_C size_t LZ4_CompressionBoundFromInputSize(size_t inputSize) {
	return LZ4_compressBound((int)inputSize);
}
AL2O3_EXTERN_C uint64_t LZ4_XXHash(void const* src, size_t length, uint64_t seed) {
	return XXH64(src, length, seed);
}

