#include "id.h"

int Id::lastId = INITIAL_ID;

Id::Id() {
    id = lastId;
    lastId += 1;
}

Id::Id(const Id& originalId) {
    id = lastId;
    lastId += 1;
}

const int& Id::getId() const {
    return id;
}

const int& Id::getLastId() {
    return lastId;
}

Id::~Id() {}
