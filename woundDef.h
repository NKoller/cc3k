#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_

class WoundDef:public Potion {
 public:
  WoundDef();
  bool hasBeenUsed();
  ~WoundDef();
};

#endif
