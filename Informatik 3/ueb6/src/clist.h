#ifndef CList_H
#define CList_H
#include <cassert>     // fuer assert

template<class T>
class CList
{
   private:
      struct ListElement
      {
         T Data;
         ListElement *Next, *Prev;
         ListElement(): Next(nullptr), Prev(nullptr) // Konstruktur
         { }
      };

      ListElement *First, *Last;
      unsigned Anzahl;

   public:
      CList();                // Konstruktor
      CList(const CList&);    // Kopierkonstruktor
      virtual ~CList();       // Destruktor

      CList& operator=(const CList&);

      bool empty() const { return Anzahl == 0; }
      unsigned size() const { return Anzahl; }

      void clear();

      // am Anfang bzw. Ende einfuegen
      void push_front(const T&);
      void push_back(const T&);

      // am Anfang bzw. Ende entnehmen
      void pop_front();
      void pop_back();

      // am Anfang bzw. Ende lesen
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      // ========================================
      // Jetzt kommt die geschachtelte
      // Klasse fuer den Iterator:
      class Iterator
      {
         private:
            ListElement* aktuell;   // Zeiger auf
                                    // aktuelles Element
         public:
            friend class CList<T>;  // wg. erase-Zugriff
                                    // auf aktuell
            Iterator(ListElement* Init = nullptr)
            : aktuell(Init)
            { }

            Iterator(const CList& L)
            {  *this = L.begin(); }

            // Variablenoperator:
            const T& operator*() const
            {  return aktuell->Data; }

            T& operator*()
            {  return aktuell->Data; }

            Iterator& operator++() // prefix
            {
               if (aktuell)
                  aktuell = aktuell->Next;
               return *this;
            }

            Iterator operator++(int) // postfix
            {
               Iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const Iterator& x) const
            {  return aktuell == x.aktuell; }

            bool operator!=(const Iterator& x) const
            {  return aktuell != x.aktuell; }

      }; // Iterator
      // Hier ist Deklaration und Definition
      // des Iterators zu Ende!
      // ========================================

      // Methoden der Klasse CList,
      // die die Klasse Iterator benutzen:

      Iterator begin() const
      {  return Iterator(First); }

      Iterator end() const
      {  return Iterator(); } // nullptr-Iterator

      void erase(Iterator& pos) // Element loeschen
      {
         if (pos.aktuell == First)
         {
            pop_front();
            pos.aktuell = First; // neuer Anfang
         }
         else
            if (pos.aktuell == Last)
            {
               pop_back();
               pos.aktuell = Last;
            }
            else
            {
               // zwischen 2 Elementen ausketten
               pos.aktuell->Next->Prev = pos.aktuell->Prev;
               pos.aktuell->Prev->Next = pos.aktuell->Next;
               ListElement *temp = pos.aktuell;
               pos.aktuell = pos.aktuell->Next;
               delete temp;
               Anzahl--;
            }
      }

      // Vor pos einfuegen
      Iterator insert(Iterator pos, const T& Wert)
      {
         if (pos == begin())
         {
            push_front(Wert);
            return Iterator(First);
         }
         if (pos == end())
         {
            push_back(Wert);
            return Iterator(Last);
         }
         // zwischen 2 Elementen einketten
         ListElement *temp = new ListElement;
         temp->Data = Wert;
         temp->Next = pos.aktuell;
         temp->Prev = pos.aktuell->Prev;
         pos.aktuell->Prev->Next = temp;
         pos.aktuell->Prev = temp;
         Anzahl++;
         return Iterator(temp);
      }
};

// ===== Implementierung der Klasse TList =====
// soweit nicht schon geschehen

template<class T>           // Konstruktor
inline CList<T>::CList()
: First(nullptr), Last(nullptr), Anzahl(0)
{ }

template<class T>           // Kopierkonstruktor
inline CList<T>::CList(const CList<T>& L)
: First(nullptr), Last(nullptr), Anzahl(0)
{
   ListElement *temp = L.Last;
   while (temp)
   {
      push_front(temp->Data);
      temp = temp->Prev;
   }
}

template<class T>           // Destruktor
inline CList<T>::~CList()
{
   while (!empty())
      pop_front();
}

template<class T>           // Zuweisungsoperator
inline CList<T>& CList<T>::operator=(const CList<T>& L)
{
   if (this != &L) // Selbstzuweisung ausschliessen
   {
      while (!empty())
         pop_front(); // alles loeschen
      // ... und neu aufbauen
      ListElement *temp = L.Last;
      while (temp)
      {
         push_front(temp->Data);
         temp = temp->Prev;
      }
   }
   return *this;
}

template<class T>
inline void CList<T>::clear()
{
   while (!empty())
      pop_front(); // alles loeschen
}

template<class T>
inline void CList<T>::push_front(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = nullptr;
   temp->Next = First;
   if (!First)
      Last=temp; // einziges Element
   else
      First->Prev = temp;
   First = temp;
   Anzahl++;
}

template<class T>
inline void CList<T>::push_back(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = Last;
   temp->Next = nullptr;
   if (!Last)
      First = temp; // einziges Element
   else
      temp->Prev->Next = temp;
   Last = temp;
   Anzahl++;
}

template<class T>
inline void CList<T>::pop_front()
{
   assert(!empty());
   ListElement *temp = First;
   First = temp->Next;
   if (!First)
      // d.h. kein weiteres Element vorhanden
      Last = nullptr;
   else
      First->Prev = nullptr;
   delete temp;
   Anzahl--;
}

template<class T>
inline void CList<T>::pop_back()
{
   assert(!empty());
   ListElement *temp = Last;
   Last = temp->Prev;
   if (!Last)
      // d.h. kein weiteres Element vorhanden
      First = nullptr;
   else
      Last->Next = nullptr;
   delete temp;
   Anzahl--;
}

template<class T>
inline T& CList<T>::front()
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline const T& CList<T>::front() const
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline T& CList<T>::back()
{
   assert(!empty());
   return Last->Data;
}

template<class T>
inline const T& CList<T>::back() const
{
   assert(!empty());
   return Last->Data;
}

#endif // CLIST_H
