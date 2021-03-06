/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_INC_APPLUNO_HXX
#define INCLUDED_SC_INC_APPLUNO_HXX

#include <svl/itemprop.hxx>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/sheet/XRecentFunctions.hpp>
#include <com/sun/star/sheet/XFunctionDescriptions.hpp>
#include <com/sun/star/sheet/XGlobalSheetSettings.hpp>
#include <com/sun/star/container/XEnumerationAccess.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <cppuhelper/implbase.hxx>
#include <rtl/ustring.hxx>
#include <sfx2/sfxmodelfactory.hxx>

com::sun::star::uno::Reference<com::sun::star::uno::XInterface> SAL_CALL
    ScSpreadsheetSettings_CreateInstance(
        const com::sun::star::uno::Reference<
            com::sun::star::lang::XMultiServiceFactory>& rSMgr );
com::sun::star::uno::Reference<com::sun::star::uno::XInterface> SAL_CALL
    ScRecentFunctionsObj_CreateInstance(
        const com::sun::star::uno::Reference<
            com::sun::star::lang::XMultiServiceFactory>& rSMgr );
com::sun::star::uno::Reference<com::sun::star::uno::XInterface> SAL_CALL
    ScFunctionListObj_CreateInstance(
        const com::sun::star::uno::Reference<
            com::sun::star::lang::XMultiServiceFactory>& rSMgr );

// Calc document
css::uno::Sequence< OUString > SAL_CALL ScDocument_getSupportedServiceNames() throw();
OUString SAL_CALL ScDocument_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScDocument_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr, SfxModelFlags _nCreationFlags ) throw( css::uno::Exception, std::exception );

// Calc XML import
css::uno::Sequence< OUString > SAL_CALL ScXMLImport_getSupportedServiceNames() throw();
OUString SAL_CALL ScXMLImport_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScXMLImport_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr ) throw( css::uno::Exception );
css::uno::Sequence< OUString > SAL_CALL ScXMLImport_Meta_getSupportedServiceNames() throw();
OUString SAL_CALL ScXMLImport_Meta_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScXMLImport_Meta_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr ) throw( css::uno::Exception );
css::uno::Sequence< OUString > SAL_CALL ScXMLImport_Styles_getSupportedServiceNames() throw();
OUString SAL_CALL ScXMLImport_Styles_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScXMLImport_Styles_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr ) throw( css::uno::Exception );
css::uno::Sequence< OUString > SAL_CALL ScXMLImport_Content_getSupportedServiceNames() throw();
OUString SAL_CALL ScXMLImport_Content_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScXMLImport_Content_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr ) throw( css::uno::Exception );
css::uno::Sequence< OUString > SAL_CALL ScXMLImport_Settings_getSupportedServiceNames() throw();
OUString SAL_CALL ScXMLImport_Settings_getImplementationName() throw();
css::uno::Reference< css::uno::XInterface > SAL_CALL ScXMLImport_Settings_createInstance(
            const css::uno::Reference< css::lang::XMultiServiceFactory > & rSMgr ) throw( css::uno::Exception );

class ScSpreadsheetSettings : public cppu::WeakImplHelper<
                                        com::sun::star::sheet::XGlobalSheetSettings,
                                        com::sun::star::beans::XPropertySet,
                                        com::sun::star::lang::XServiceInfo>
{
private:
    SfxItemPropertySet      aPropSet;

    bool getPropertyBool(const OUString& aPropertyName) throw (css::uno::RuntimeException);
    sal_Int16 getPropertyInt16(const OUString& aPropertyName) throw (css::uno::RuntimeException);
    void setProperty(const OUString& aPropertyName, bool p1) throw (css::uno::RuntimeException)
        { setPropertyValue( aPropertyName, css::uno::Any(p1) ); }
    void setProperty(const OUString& aPropertyName, sal_Int16 p1) throw (css::uno::RuntimeException)
        { setPropertyValue( aPropertyName, css::uno::Any(p1) ); }
public:
                            ScSpreadsheetSettings();
    virtual                 ~ScSpreadsheetSettings();

    static OUString  getImplementationName_Static();
    static ::com::sun::star::uno::Sequence< OUString > getSupportedServiceNames_Static();

    // XGlobalSheetSettings
    virtual sal_Bool SAL_CALL getMoveSelection() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("MoveSelection"); }
    virtual void SAL_CALL setMoveSelection(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("MoveSelection", (bool)p1); }
    virtual sal_Int16 SAL_CALL getMoveDirection() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyInt16("MoveDirection"); }
    virtual void SAL_CALL setMoveDirection(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("MoveDirection", p1); }
    virtual sal_Bool SAL_CALL getEnterEdit() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("EnterEdit"); }
    virtual void SAL_CALL setEnterEdit(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("EnterEdit", (bool)p1); }
    virtual sal_Bool SAL_CALL getExtendFormat() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("ExtendFormat"); }
    virtual void SAL_CALL setExtendFormat(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("ExtendFormat", (bool)p1); }
    virtual sal_Bool SAL_CALL getRangeFinder() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("RangeFinder"); }
    virtual void SAL_CALL setRangeFinder(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("RangeFinder", (bool)p1); }
    virtual sal_Bool SAL_CALL getExpandReferences() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("ExpandReferences"); }
    virtual void SAL_CALL setExpandReferences(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("ExpandReferences", (bool)p1); }
    virtual sal_Bool SAL_CALL getMarkHeader() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("MarkHeader"); }
    virtual void SAL_CALL setMarkHeader(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("MarkHeader", (bool)p1); }
    virtual sal_Bool SAL_CALL getUseTabCol() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("UseTabCol"); }
    virtual void SAL_CALL setUseTabCol(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("UseTabCol", (bool)p1); }
    virtual sal_Int16 SAL_CALL getMetric() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyInt16("Metric"); }
    virtual void SAL_CALL setMetric(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("Metric", p1); }
    virtual sal_Int16 SAL_CALL getScale() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyInt16("Scale"); }
    virtual void SAL_CALL setScale(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("Scale", p1); }
    virtual sal_Bool SAL_CALL getDoAutoComplete() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("DoAutoComplete"); }
    virtual void SAL_CALL setDoAutoComplete(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("DoAutoComplete", (bool)p1); }
    virtual sal_Int16 SAL_CALL getStatusBarFunction() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyInt16("StatusBarFunction"); }
    virtual void SAL_CALL setStatusBarFunction(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("StatusBarFunction", p1); }
    virtual css::uno::Sequence<OUString> SAL_CALL getUserLists() throw (css::uno::RuntimeException, std::exception) override
        {
           css::uno::Any any = getPropertyValue("UserLists");
           css::uno::Sequence<OUString> b;
           any >>= b;
           return b;
        }
    virtual void SAL_CALL setUserLists(const css::uno::Sequence<OUString>& p1) throw (css::uno::RuntimeException, std::exception) override
        { setPropertyValue( "UserLists", css::uno::Any(p1) ); }
    virtual sal_Int16 SAL_CALL getLinkUpdateMode() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyInt16("LinkUpdateMode"); }
    virtual void SAL_CALL setLinkUpdateMode(sal_Int16 p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("LinkUpdateMode", p1); }
    virtual sal_Bool SAL_CALL getPrintAllSheets() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("PrintAllSheets"); }
    virtual void SAL_CALL setPrintAllSheets(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("PrintAllSheets", (bool)p1); }
    virtual sal_Bool SAL_CALL getPrintEmptyPages() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("PrintEmptyPages"); }
    virtual void SAL_CALL setPrintEmptyPages(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("PrintEmptyPages", (bool)p1); }
    virtual sal_Bool SAL_CALL getUsePrinterMetrics() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("UsePrinterMetrics"); }
    virtual void SAL_CALL setUsePrinterMetrics(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("UsePrinterMetrics", (bool)p1); }
    virtual sal_Bool SAL_CALL getReplaceCellsWarning() throw (css::uno::RuntimeException, std::exception) override
        { return getPropertyBool("ReplaceCellsWarning"); }
    virtual void SAL_CALL setReplaceCellsWarning(sal_Bool p1) throw (css::uno::RuntimeException, std::exception) override
        { setProperty("ReplaceCellsWarning", (bool)p1); }

    // XPropertySet
    virtual ::com::sun::star::uno::Reference< ::com::sun::star::beans::XPropertySetInfo >
                            SAL_CALL getPropertySetInfo()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual void SAL_CALL   setPropertyValue( const OUString& aPropertyName,
                                    const ::com::sun::star::uno::Any& aValue )
                                throw (::com::sun::star::beans::UnknownPropertyException,
                                       ::com::sun::star::beans::PropertyVetoException,
                                       ::com::sun::star::lang::IllegalArgumentException,
                                       ::com::sun::star::lang::WrappedTargetException,
                                       ::com::sun::star::uno::RuntimeException,
                                       std::exception) override;
    virtual ::com::sun::star::uno::Any SAL_CALL getPropertyValue(
                                    const OUString& PropertyName )
                                throw (::com::sun::star::beans::UnknownPropertyException,
                                       ::com::sun::star::lang::WrappedTargetException,
                                       ::com::sun::star::uno::RuntimeException,
                                       std::exception) override;
    virtual void SAL_CALL   addPropertyChangeListener( const OUString& aPropertyName,
                                    const ::com::sun::star::uno::Reference<
                                        ::com::sun::star::beans::XPropertyChangeListener >& xListener )
                                throw(::com::sun::star::beans::UnknownPropertyException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual void SAL_CALL   removePropertyChangeListener( const OUString& aPropertyName,
                                    const ::com::sun::star::uno::Reference<
                                        ::com::sun::star::beans::XPropertyChangeListener >& aListener )
                                throw(::com::sun::star::beans::UnknownPropertyException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual void SAL_CALL   addVetoableChangeListener( const OUString& PropertyName,
                                    const ::com::sun::star::uno::Reference<
                                        ::com::sun::star::beans::XVetoableChangeListener >& aListener )
                                throw(::com::sun::star::beans::UnknownPropertyException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual void SAL_CALL   removeVetoableChangeListener( const OUString& PropertyName,
                                    const ::com::sun::star::uno::Reference<
                                        ::com::sun::star::beans::XVetoableChangeListener >& aListener )
                                throw(::com::sun::star::beans::UnknownPropertyException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName )
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
};

class ScRecentFunctionsObj : public cppu::WeakImplHelper<
                                        com::sun::star::sheet::XRecentFunctions,
                                        com::sun::star::lang::XServiceInfo>
{
public:
                            ScRecentFunctionsObj();
    virtual                 ~ScRecentFunctionsObj();

                            // XRecentFunctions
    virtual ::com::sun::star::uno::Sequence< sal_Int32 > SAL_CALL getRecentFunctionIds()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual void SAL_CALL setRecentFunctionIds( const ::com::sun::star::uno::Sequence<
                                                sal_Int32 >& aRecentFunctionIds )
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Int32 SAL_CALL getMaxRecentFunctions()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XServiceInfo
    virtual OUString SAL_CALL getImplementationName()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName )
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
};

class ScFunctionListObj : public cppu::WeakImplHelper<
                                        com::sun::star::sheet::XFunctionDescriptions,
                                        com::sun::star::container::XEnumerationAccess,
                                        com::sun::star::container::XNameAccess,
                                        com::sun::star::lang::XServiceInfo>
{
public:
                            ScFunctionListObj();
    virtual                 ~ScFunctionListObj();

                            // XFunctionDescriptions
    virtual ::com::sun::star::uno::Sequence< ::com::sun::star::beans::PropertyValue > SAL_CALL
                            getById( sal_Int32 nId )
                                throw(::com::sun::star::lang::IllegalArgumentException,
                                ::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XNameAccess
    virtual ::com::sun::star::uno::Any SAL_CALL getByName( const OUString& aName )
                                throw(::com::sun::star::container::NoSuchElementException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getElementNames()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Bool SAL_CALL hasByName( const OUString& aName )
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XIndexAccess
    virtual sal_Int32 SAL_CALL getCount() throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual ::com::sun::star::uno::Any SAL_CALL getByIndex( sal_Int32 Index )
                                throw(::com::sun::star::lang::IndexOutOfBoundsException,
                                    ::com::sun::star::lang::WrappedTargetException,
                                    ::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XEnumerationAccess
    virtual ::com::sun::star::uno::Reference< ::com::sun::star::container::XEnumeration > SAL_CALL
                            createEnumeration() throw(::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XElementAccess
    virtual ::com::sun::star::uno::Type SAL_CALL getElementType()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Bool SAL_CALL hasElements() throw(::com::sun::star::uno::RuntimeException, std::exception) override;

                            // XServiceInfo
    virtual OUString SAL_CALL getImplementationName()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName )
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
    virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames()
                                throw(::com::sun::star::uno::RuntimeException, std::exception) override;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
