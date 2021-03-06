/************************************************************/
/*    NAME: Sam Reed                                        */
/*    ORGN: UNH                                             */
/*    FILE: BHV_OA.h                                        */
/*    DATE: June 2016                                       */
/************************************************************/

#ifndef A_HEADER
#define A_HEADER

#include <string>
#include "IvPBehavior.h"
#include "AOF.h"
//#include "../../../../MOOS/MOOSLIB/MOOSApp.h"
//#include "../../../MOOS_V10.0.3_May1215/MOOSCore/Core/libMOOS/include/MOOS/Compatibility/Core/MOOSGenLib/ProcessConfigReader.h"

class BHV_OA : public IvPBehavior {
public:
  BHV_OA(IvPDomain);
  ~BHV_OA() {};
  
  bool         setParam(std::string, std::string);
  void         onSetParamComplete();
  void         onCompleteState();
  void         onIdleState();
  void         onHelmStart();
  void         postConfigStatus();
  void         onRunToIdleState();
  void         onIdleToRunState();
  IvPFunction* onRunState();
  

protected: // Local Utility functions
  IvPFunction* buildFunctionWithZAIC();
	IvPFunction* buildIvPFunction();
	IvPFunction* buildZAIC_Vector();

protected: // Configuration parameters

protected: // State variables
  string m_obstacles, m_obs_info, m_WPT;
	double m_dLatOrigin, m_dLonOrigin;
  double m_ASV_x, m_ASV_y, m_ASV_head, m_speed;
  int m_num_obs, m_WPT_x, m_WPT_y;
	//CProcessConfigReader m_MissionReader;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_OA(domain);}
}
#endif
