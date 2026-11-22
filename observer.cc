export module observer;
import <vector>;

export class Observer {
 public:
  virtual void notify() = 0;
  virtual ~Observer();
};

export class Subject {
  std::vector<Observer*> observers;

 public:
  Subject();
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual ~Subject()=0;
};
