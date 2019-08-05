# hash-map

a hash map in c.  uses a simple hash function and splits the keys across buckets.  stores the keys by value, as pointers to byte buffers.  this means that the same value in a byte buffer (but a different key pointer) will be the same key in the map, so it'll be a replace.  key and value buffer pointers are not freed when delets happen in the map (but the kv is returned), so it's safe to pass an arbitrary memory location and length (provided you own it!)

layering:

hash(key)
key+value = kv
list[node] = kv
hashmap = bucket[list]
