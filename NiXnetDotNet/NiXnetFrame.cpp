#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetFrame::NiXnetFrame(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}

NetString NiXnetFrame::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropFrm_Name);
}

u32 NiXnetFrame::Identifier::get()
{
   return NiXnet::GetDbValue<u32>(m_handle, nxPropFrm_ID);
}

cli::array<NiXnetSignal^>^ NiXnetFrame::Signals::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropFrm_SigRefs);
   cli::array<NiXnetSignal^>^ signals = gcnew cli::array<NiXnetSignal^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      signals[i] = gcnew NiXnetSignal(handles[i]);
   }
   return signals;
}

NetString NiXnetFrame::Comment::get()
{
    return NiXnet::GetDbStringValue(m_handle, nxPropFrm_Comment);
}

u32 NiXnetFrame::ConfigStatus::get()
{
    return NiXnet::GetDbValue<u32>(m_handle, nxPropFrm_ConfigStatus);
}

bool NiXnetFrame::CANExtID::get()
{
    return NiXnet::GetDbValue<bool>(m_handle, nxPropFrm_CANExtID);
}

NiXnetCANTimingType NiXnetFrame::CANTimingType::get()
{
    return static_cast<NiXnetCANTimingType>(NiXnet::GetDbValue<u32>(m_handle, nxPropFrm_CANTimingType));
}

f64 NiXnetFrame::CANTxTime::get()
{
    return NiXnet::GetDbValue<f64>(m_handle, nxPropFrm_CANTxTime);
}

NiXnetCANIoMode NiXnetFrame::CANIoMode::get()
{
    return static_cast<NiXnetCANIoMode>(NiXnet::GetDbValue<u32>(m_handle, nxPropFrm_CANioMode));
}

NetString NiXnetFrame::ToString()
{
   return this->Name;
}
