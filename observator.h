#ifndef OBSERVATOR_H
#define OBSERVATOR_H

#endif // OBSERVATOR_H


template <class T>
class Observer
   {
   public:
      Observer() {}
      virtual ~Observer() {}
      /**
       * \brief Applique une série d'instructions.
       * \param subject Sujet qui a ete modifie.
       */
      virtual void update(T *subject)= 0;
   };


template <class T>
class Subject
   {
   public:
      Subject() {}
      virtual ~Subject() {}

      /**
       * \brief Attache un observateur a ce sujet.
       * \param observer L'observateur a attacher.
       */
      void attach (Observer<T> &observer)
         {
         m_observers.push_back(&observer);
         }

      /**
       * \brief Notifie chaque observateur qu'un changement a eu lieu sur l'objet.
       * \details On appelle la fonction Observer::update() de chaque observateur afin
       * qu'il reagissent aux changements.
       */
      void notify ()
         {
         typename std::vector<Observer<T> *>::iterator it;
         for (it=m_observers.begin();it!=m_observers.end();it++)
              (*it)->update(static_cast<T *>(this));
         }
   private:

      /**
       * \brief Vector contenant les observateur du sujet.
       */
      std::vector<Observer<T> *> m_observers;
   };
