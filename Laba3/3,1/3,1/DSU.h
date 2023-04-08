#pragma once

struct Vertex {
	Vertex* parent;
};

void set_make(Vertex* v);

Vertex* set_find(Vertex* v);

void set_union(Vertex* v1, Vertex* v2);
