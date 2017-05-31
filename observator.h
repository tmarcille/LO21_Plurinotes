#ifndef OBSERVATOR_H
#define OBSERVATOR_H

#endif // OBSERVATOR_H


template <class T>
class Observer
   {
   public:
      Observer() {}
      virtual ~Observer() {}
      virtual void update(T *subject)= 0;
   };


template <class T>
class Subject
   {
   public:
      Subject() {}
      virtual ~Subject() {}
      void attach (Observer<T> &observer)
         {
         m_observers.push_back(&observer);
         }
      void notify ()
         {
         typename std::vector<Observer<T> *>::iterator it;
         for (it=m_observers.begin();it!=m_observers.end();it++)
              (*it)->update(static_cast<T *>(this));
         }
   private:
      std::vector<Observer<T> *> m_observers;
   };
