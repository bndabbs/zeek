// See the file "COPYING" in the main distribution directory for copyright.

#ifndef ANALYZER_PROTOCOL_GSSAPI_GSSAPI_H
#define ANALYZER_PROTOCOL_GSSAPI_GSSAPI_H

#include "events.bif.h"
#include "analyzer/protocol/tcp/TCP.h"

#include "gssapi_pac.h"

namespace analyzer { namespace gssapi {

class GSSAPI_Analyzer

: public tcp::TCP_ApplicationAnalyzer {

public:
	explicit GSSAPI_Analyzer(Connection* conn);
	~GSSAPI_Analyzer() override;

	// Overriden from Analyzer.
	void Done() override;

	void DeliverStream(int len, const u_char* data, bool orig) override;
	void Undelivered(uint64_t seq, int len, bool orig) override;

	// Overriden from tcp::TCP_ApplicationAnalyzer.
	void EndpointEOF(bool is_orig) override;

	static analyzer::Analyzer* Instantiate(Connection* conn)
		{ return new GSSAPI_Analyzer(conn); }

protected:
	binpac::GSSAPI::GSSAPI_Conn* interp;
};

} } // namespace analyzer::*

#endif
