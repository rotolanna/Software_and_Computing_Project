// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME AnaFOOTDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Evento.h"
#include "Initialization.h"
#include "Booking.h"
#include "Init_in_each_event.h"
#include "STRUCT.h"
#include "constant.h"
#include "Generation.h"
#include "Reconstruction.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_Evento(void *p = 0);
   static void *newArray_Evento(Long_t size, void *p);
   static void delete_Evento(void *p);
   static void deleteArray_Evento(void *p);
   static void destruct_Evento(void *p);
   static void streamer_Evento(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Evento*)
   {
      ::Evento *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Evento >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Evento", ::Evento::Class_Version(), "Evento.h", 14,
                  typeid(::Evento), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Evento::Dictionary, isa_proxy, 16,
                  sizeof(::Evento) );
      instance.SetNew(&new_Evento);
      instance.SetNewArray(&newArray_Evento);
      instance.SetDelete(&delete_Evento);
      instance.SetDeleteArray(&deleteArray_Evento);
      instance.SetDestructor(&destruct_Evento);
      instance.SetStreamerFunc(&streamer_Evento);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Evento*)
   {
      return GenerateInitInstanceLocal((::Evento*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Evento*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *Initialization_Dictionary();
   static void Initialization_TClassManip(TClass*);
   static void *new_Initialization(void *p = 0);
   static void *newArray_Initialization(Long_t size, void *p);
   static void delete_Initialization(void *p);
   static void deleteArray_Initialization(void *p);
   static void destruct_Initialization(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Initialization*)
   {
      ::Initialization *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Initialization));
      static ::ROOT::TGenericClassInfo 
         instance("Initialization", "Initialization.h", 19,
                  typeid(::Initialization), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Initialization_Dictionary, isa_proxy, 0,
                  sizeof(::Initialization) );
      instance.SetNew(&new_Initialization);
      instance.SetNewArray(&newArray_Initialization);
      instance.SetDelete(&delete_Initialization);
      instance.SetDeleteArray(&deleteArray_Initialization);
      instance.SetDestructor(&destruct_Initialization);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Initialization*)
   {
      return GenerateInitInstanceLocal((::Initialization*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Initialization*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Initialization_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Initialization*)0x0)->GetClass();
      Initialization_TClassManip(theClass);
   return theClass;
   }

   static void Initialization_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Init_in_each_event_Dictionary();
   static void Init_in_each_event_TClassManip(TClass*);
   static void *new_Init_in_each_event(void *p = 0);
   static void *newArray_Init_in_each_event(Long_t size, void *p);
   static void delete_Init_in_each_event(void *p);
   static void deleteArray_Init_in_each_event(void *p);
   static void destruct_Init_in_each_event(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Init_in_each_event*)
   {
      ::Init_in_each_event *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Init_in_each_event));
      static ::ROOT::TGenericClassInfo 
         instance("Init_in_each_event", "Init_in_each_event.h", 9,
                  typeid(::Init_in_each_event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Init_in_each_event_Dictionary, isa_proxy, 0,
                  sizeof(::Init_in_each_event) );
      instance.SetNew(&new_Init_in_each_event);
      instance.SetNewArray(&newArray_Init_in_each_event);
      instance.SetDelete(&delete_Init_in_each_event);
      instance.SetDeleteArray(&deleteArray_Init_in_each_event);
      instance.SetDestructor(&destruct_Init_in_each_event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Init_in_each_event*)
   {
      return GenerateInitInstanceLocal((::Init_in_each_event*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Init_in_each_event*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Init_in_each_event_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Init_in_each_event*)0x0)->GetClass();
      Init_in_each_event_TClassManip(theClass);
   return theClass;
   }

   static void Init_in_each_event_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Booking_Dictionary();
   static void Booking_TClassManip(TClass*);
   static void *new_Booking(void *p = 0);
   static void *newArray_Booking(Long_t size, void *p);
   static void delete_Booking(void *p);
   static void deleteArray_Booking(void *p);
   static void destruct_Booking(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Booking*)
   {
      ::Booking *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Booking));
      static ::ROOT::TGenericClassInfo 
         instance("Booking", "Booking.h", 13,
                  typeid(::Booking), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Booking_Dictionary, isa_proxy, 0,
                  sizeof(::Booking) );
      instance.SetNew(&new_Booking);
      instance.SetNewArray(&newArray_Booking);
      instance.SetDelete(&delete_Booking);
      instance.SetDeleteArray(&deleteArray_Booking);
      instance.SetDestructor(&destruct_Booking);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Booking*)
   {
      return GenerateInitInstanceLocal((::Booking*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Booking*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Booking_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Booking*)0x0)->GetClass();
      Booking_TClassManip(theClass);
   return theClass;
   }

   static void Booking_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Generation_Dictionary();
   static void Generation_TClassManip(TClass*);
   static void *new_Generation(void *p = 0);
   static void *newArray_Generation(Long_t size, void *p);
   static void delete_Generation(void *p);
   static void deleteArray_Generation(void *p);
   static void destruct_Generation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Generation*)
   {
      ::Generation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Generation));
      static ::ROOT::TGenericClassInfo 
         instance("Generation", "Generation.h", 20,
                  typeid(::Generation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Generation_Dictionary, isa_proxy, 0,
                  sizeof(::Generation) );
      instance.SetNew(&new_Generation);
      instance.SetNewArray(&newArray_Generation);
      instance.SetDelete(&delete_Generation);
      instance.SetDeleteArray(&deleteArray_Generation);
      instance.SetDestructor(&destruct_Generation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Generation*)
   {
      return GenerateInitInstanceLocal((::Generation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Generation*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Generation_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Generation*)0x0)->GetClass();
      Generation_TClassManip(theClass);
   return theClass;
   }

   static void Generation_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Reconstruction_Dictionary();
   static void Reconstruction_TClassManip(TClass*);
   static void *new_Reconstruction(void *p = 0);
   static void *newArray_Reconstruction(Long_t size, void *p);
   static void delete_Reconstruction(void *p);
   static void deleteArray_Reconstruction(void *p);
   static void destruct_Reconstruction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Reconstruction*)
   {
      ::Reconstruction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Reconstruction));
      static ::ROOT::TGenericClassInfo 
         instance("Reconstruction", "Reconstruction.h", 24,
                  typeid(::Reconstruction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Reconstruction_Dictionary, isa_proxy, 0,
                  sizeof(::Reconstruction) );
      instance.SetNew(&new_Reconstruction);
      instance.SetNewArray(&newArray_Reconstruction);
      instance.SetDelete(&delete_Reconstruction);
      instance.SetDeleteArray(&deleteArray_Reconstruction);
      instance.SetDestructor(&destruct_Reconstruction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Reconstruction*)
   {
      return GenerateInitInstanceLocal((::Reconstruction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Reconstruction*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Reconstruction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Reconstruction*)0x0)->GetClass();
      Reconstruction_TClassManip(theClass);
   return theClass;
   }

   static void Reconstruction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Evento::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Evento::Class_Name()
{
   return "Evento";
}

//______________________________________________________________________________
const char *Evento::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Evento*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Evento::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Evento*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Evento::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Evento*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Evento::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Evento*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Evento::Streamer(TBuffer &R__b)
{
   // Stream an object of class Evento.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b.StreamObject(&(eve),typeid(eve));
      R__b.CheckByteCount(R__s, R__c, Evento::IsA());
   } else {
      R__c = R__b.WriteVersion(Evento::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b.StreamObject(&(eve),typeid(eve));
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Evento(void *p) {
      return  p ? new(p) ::Evento : new ::Evento;
   }
   static void *newArray_Evento(Long_t nElements, void *p) {
      return p ? new(p) ::Evento[nElements] : new ::Evento[nElements];
   }
   // Wrapper around operator delete
   static void delete_Evento(void *p) {
      delete ((::Evento*)p);
   }
   static void deleteArray_Evento(void *p) {
      delete [] ((::Evento*)p);
   }
   static void destruct_Evento(void *p) {
      typedef ::Evento current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Evento(TBuffer &buf, void *obj) {
      ((::Evento*)obj)->::Evento::Streamer(buf);
   }
} // end of namespace ROOT for class ::Evento

namespace ROOT {
   // Wrappers around operator new
   static void *new_Initialization(void *p) {
      return  p ? new(p) ::Initialization : new ::Initialization;
   }
   static void *newArray_Initialization(Long_t nElements, void *p) {
      return p ? new(p) ::Initialization[nElements] : new ::Initialization[nElements];
   }
   // Wrapper around operator delete
   static void delete_Initialization(void *p) {
      delete ((::Initialization*)p);
   }
   static void deleteArray_Initialization(void *p) {
      delete [] ((::Initialization*)p);
   }
   static void destruct_Initialization(void *p) {
      typedef ::Initialization current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Initialization

namespace ROOT {
   // Wrappers around operator new
   static void *new_Init_in_each_event(void *p) {
      return  p ? new(p) ::Init_in_each_event : new ::Init_in_each_event;
   }
   static void *newArray_Init_in_each_event(Long_t nElements, void *p) {
      return p ? new(p) ::Init_in_each_event[nElements] : new ::Init_in_each_event[nElements];
   }
   // Wrapper around operator delete
   static void delete_Init_in_each_event(void *p) {
      delete ((::Init_in_each_event*)p);
   }
   static void deleteArray_Init_in_each_event(void *p) {
      delete [] ((::Init_in_each_event*)p);
   }
   static void destruct_Init_in_each_event(void *p) {
      typedef ::Init_in_each_event current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Init_in_each_event

namespace ROOT {
   // Wrappers around operator new
   static void *new_Booking(void *p) {
      return  p ? new(p) ::Booking : new ::Booking;
   }
   static void *newArray_Booking(Long_t nElements, void *p) {
      return p ? new(p) ::Booking[nElements] : new ::Booking[nElements];
   }
   // Wrapper around operator delete
   static void delete_Booking(void *p) {
      delete ((::Booking*)p);
   }
   static void deleteArray_Booking(void *p) {
      delete [] ((::Booking*)p);
   }
   static void destruct_Booking(void *p) {
      typedef ::Booking current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Booking

namespace ROOT {
   // Wrappers around operator new
   static void *new_Generation(void *p) {
      return  p ? new(p) ::Generation : new ::Generation;
   }
   static void *newArray_Generation(Long_t nElements, void *p) {
      return p ? new(p) ::Generation[nElements] : new ::Generation[nElements];
   }
   // Wrapper around operator delete
   static void delete_Generation(void *p) {
      delete ((::Generation*)p);
   }
   static void deleteArray_Generation(void *p) {
      delete [] ((::Generation*)p);
   }
   static void destruct_Generation(void *p) {
      typedef ::Generation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Generation

namespace ROOT {
   // Wrappers around operator new
   static void *new_Reconstruction(void *p) {
      return  p ? new(p) ::Reconstruction : new ::Reconstruction;
   }
   static void *newArray_Reconstruction(Long_t nElements, void *p) {
      return p ? new(p) ::Reconstruction[nElements] : new ::Reconstruction[nElements];
   }
   // Wrapper around operator delete
   static void delete_Reconstruction(void *p) {
      delete ((::Reconstruction*)p);
   }
   static void deleteArray_Reconstruction(void *p) {
      delete [] ((::Reconstruction*)p);
   }
   static void destruct_Reconstruction(void *p) {
      typedef ::Reconstruction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Reconstruction

namespace {
  void TriggerDictionaryInitialization_AnaFOOTDict_Impl() {
    static const char* headers[] = {
"Evento.h",
"Initialization.h",
"Booking.h",
"Init_in_each_event.h",
"STRUCT.h",
"constant.h",
"Generation.h",
"Reconstruction.h",
0
    };
    static const char* includePaths[] = {
"/mnt/c/Users/Annamaria/Desktop/ROOT/root/include",
"/mnt/c/Users/Annamaria/Desktop/esame/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "AnaFOOTDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Evento.h")))  Evento;
class __attribute__((annotate("$clingAutoload$Initialization.h")))  Initialization;
class __attribute__((annotate("$clingAutoload$Init_in_each_event.h")))  __attribute__((annotate("$clingAutoload$Booking.h")))  Init_in_each_event;
class __attribute__((annotate("$clingAutoload$Booking.h")))  Booking;
class __attribute__((annotate("$clingAutoload$Generation.h")))  Generation;
class __attribute__((annotate("$clingAutoload$Reconstruction.h")))  Reconstruction;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "AnaFOOTDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Evento.h"
#include "Initialization.h"
#include "Booking.h"
#include "Init_in_each_event.h"
#include "STRUCT.h"
#include "constant.h"
#include "Generation.h"
#include "Reconstruction.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Booking", payloadCode, "@",
"Evento", payloadCode, "@",
"Generation", payloadCode, "@",
"Init_in_each_event", payloadCode, "@",
"Initialization", payloadCode, "@",
"Reconstruction", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("AnaFOOTDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_AnaFOOTDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_AnaFOOTDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_AnaFOOTDict() {
  TriggerDictionaryInitialization_AnaFOOTDict_Impl();
}
