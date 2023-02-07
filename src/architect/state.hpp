// Copyright (c)
// https://www.cnblogs.com/lizhanwu/p/4437532.html
// 在實際開發中，我們經常會遇到這種情況；一個對像有多種狀態，
// 在每一個狀態下，都會有不同的行為。那麼在代碼中我們經常是這樣實現的。
// typedef enum tagState
// {
//      state0,
//      state1,
//      state2
// }State;
// void Action(State actionState)
// {
//      if (actionState == state0)
//      {
//           // DoSomething
//      }
//      else if (actionState == state1)
//      {
//           // DoSomething
//      }
//      else if (actionState == state2)
//      {
//           // DoSomething
//      }
//      else
//      {
//           // DoSomething
//      }
// }
// 而這種就好比簡單工廠模式，當我們增加新的狀態類型時，我們又需要修改原來的代碼，
// 這種對於測試是很不利的；由於簡單工廠的缺點那麼的明顯，後來的工廠模式就克服了這個缺點，
// 我們就可以藉鑑工程模式，
// 來解決這種隨著狀態增加而出現的多分支結構，而這就是我今天要總結的狀態模式。

#ifndef SRC_ARCHITECT_STATE_HPP_
#define SRC_ARCHITECT_STATE_HPP_
namespace architect {
class Context;

class StateInterface {
 public:
    // 有些文章說這裡是處理完後改變當前狀態(設置為下一個狀態)，本案例不需要故沒有實現
    virtual void handle(Context* context) = 0;
};

class Context {
 private:
    // 關鍵: 這裡可以塞入任何 state，讓 Context->request() 做出變化
    StateInterface* state_;

 public:
    explicit Context(StateInterface* state) : state_(state) {}

    ~Context() {
        std::cout << ">> Context destructor" << std::endl;
        delete state_;
    }

    void request() {
        if (state_) {
            // 這裡可自由發揮
            // 像是 state_ 可以呼叫其他元件，在動作
            state_->handle(this);
        }
    }

    /// The Context allows changing the State object at runtime.
    void changeState(StateInterface* state) {
        if (state_ != nullptr) {
            delete state_;
        }
        state_ = state;
    }
};

class StateA : public StateInterface {
 public:
    void handle(Context* context) override {
        std::cout << "StateA handles request" << std::endl;
    }
};

class StateB : public StateInterface {
 public:
    void handle(Context* context) override {
        std::cout << "StateB handles request" << std::endl;
    }
};

}  // namespace architect
#endif  // SRC_ARCHITECT_STATE_HPP_
