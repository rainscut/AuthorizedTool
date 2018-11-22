#include "LienceKit.h"
#include "LienceCreator.h"
#include "LienceValidator.h"


LienceKit::LienceKit()
{
    _c = new LienceCreator();
    _v = new LienceValidator();
}

LienceKit::~LienceKit()
{
    delete _c;
    delete _v;
}

bool LienceKit::isLienceFileVaild(const char *path)
{
    return _v->isVaild(path);
}

bool LienceKit::createLienceFile(const char *path, uint16_t days, MachineInfo_t *info)
{
    return _c->create(path, info, days);
}
