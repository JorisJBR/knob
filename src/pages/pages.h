#pragma once
#include "esphome.h"

class Page {
 public:
  virtual void dial_increase() {}
  virtual void dial_decrease() {}
  virtual void single_press()) {}
  virtual void double_press() {}
  virtual void on_show() {}
};

class LightPage : public Page {
 public:
  void dial_increase() override {
    id(light_brightness) += 1;
  }
  void dial_decrease() override {
    id(light_brightness) -= 1;
  }
  void single_press() override {
    id(light_on) = !id(light_on);
  }
  void double_press() override {
    //no op
  }
};
static LightPage light_page;
id(current_page) = &light_page;

// class PageRegistry {
//  public:
//   void add(Page* p);
//   void clear();
//   Page* current();
//   void next();
//   void prev();

//  private:
//   std::vector<Page*> pages_;
//   int index_ = 0;
// };

// class PageFactory {
//  public:
//   static Page* create(const std::string &type,
//                       const std::string &entity,
//                       const std::string &label);
// };
