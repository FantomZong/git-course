#include "DSU.h"

void set_make(Vertex* v)
{
	v->parent = v;
}

Vertex* set_find(Vertex* v)
{
	if (v->parent == v)
		return v;
	set_find(v->parent);
}

void set_union(Vertex* v1, Vertex* v2)
{
	set_find(v2)->parent = v1;
}
