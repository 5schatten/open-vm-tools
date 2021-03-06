/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/ResponseDoc/CResponseHeaderDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ResponseXml/ResponseHeaderXml.h"

using namespace Caf;

void ResponseHeaderXml::add(
	const SmartPtrCResponseHeaderDoc responseHeaderDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ResponseHeaderXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(responseHeaderDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string versionVal = responseHeaderDoc->getVersion();
		CAF_CM_VALIDATE_STRING(versionVal);
		thisXml->addAttribute("version", versionVal);

		const std::string createdDateTimeVal = responseHeaderDoc->getCreatedDateTime();
		CAF_CM_VALIDATE_STRING(createdDateTimeVal);
		thisXml->addAttribute("createdDateTime", createdDateTimeVal);

		const std::string sequenceNumberVal =
				CStringConv::toString<uint32>(responseHeaderDoc->getSequenceNumber());
		CAF_CM_VALIDATE_STRING(sequenceNumberVal);
		thisXml->addAttribute("sequenceNumber", sequenceNumberVal);

		const std::string isFinalResponseVal = responseHeaderDoc->getIsFinalResponse() ? "true" : "false";
		CAF_CM_VALIDATE_STRING(isFinalResponseVal);
		thisXml->addAttribute("isFinalResponse", isFinalResponseVal);

		const std::string sessionIdVal =
			BasePlatform::UuidToString(responseHeaderDoc->getSessionId());
		if (! sessionIdVal.empty()) {
			thisXml->addAttribute("sessionId", sessionIdVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCResponseHeaderDoc ResponseHeaderXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ResponseHeaderXml", "parse");

	SmartPtrCResponseHeaderDoc responseHeaderDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string versionVal =
			thisXml->findRequiredAttribute("version");

		const std::string createdDateTimeVal =
			thisXml->findRequiredAttribute("createdDateTime");

		const std::string sequenceNumberStrVal =
			thisXml->findRequiredAttribute("sequenceNumber");
		uint32 sequenceNumberVal = 0;
		if (! sequenceNumberStrVal.empty()) {
			sequenceNumberVal = CStringConv::fromString<uint32>(sequenceNumberStrVal);
		}

		const std::string isFinalResponseStrVal =
			thisXml->findRequiredAttribute("isFinalResponse");
		bool isFinalResponseVal = false;
		if (! isFinalResponseStrVal.empty()) {
			isFinalResponseVal = (isFinalResponseStrVal.compare("true") == 0)  ? true : false;
		}

		const std::string sessionIdStrVal =
			thisXml->findOptionalAttribute("sessionId");
		UUID sessionIdVal = CAFCOMMON_GUID_NULL;
		if (! sessionIdStrVal.empty()) {
			BasePlatform::UuidFromString(sessionIdStrVal.c_str(), sessionIdVal);
		}

		responseHeaderDoc.CreateInstance();
		responseHeaderDoc->initialize(
			versionVal,
			createdDateTimeVal,
			sequenceNumberVal,
			isFinalResponseVal,
			sessionIdVal);
	}
	CAF_CM_EXIT;

	return responseHeaderDoc;
}

