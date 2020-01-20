#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetCluster::NiXnetCluster(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}

NiXnetAppProtocol NiXnetCluster::AppProtocol::get()
{
    return static_cast<NiXnetAppProtocol>(NiXnet::GetDbValue<u32>(m_handle, nxPropClst_ApplicationProtocol));
}

u64 NiXnetCluster::BaudRate::get()
{
    return NiXnet::GetDbValue<u64>(m_handle, nxPropClst_BaudRate64);
}

NetString NiXnetCluster::Comment::get()
{
    return NiXnet::GetDbStringValue(m_handle, nxPropClst_Comment);
}

i32 NiXnetCluster::ConfigStatus::get()
{
    return NiXnet::GetDbValue<i32>(m_handle, nxPropClst_ConfigStatus);
}

//DataBase

cli::array<NiXnetEcu^>^ NiXnetCluster::Ecus::get()
{
    cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_ECURefs);
    cli::array<NiXnetEcu^>^ ecus = gcnew cli::array<NiXnetEcu^>(handles->Length);
    for (int i = 0; i < handles->Length; i++)
    {
        ecus[i] = gcnew NiXnetEcu(handles[i]);
    }
    return ecus;
}

cli::array<NiXnetFrame^>^ NiXnetCluster::Frames::get()
{
    cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_FrmRefs);
    cli::array<NiXnetFrame^>^ frames = gcnew cli::array<NiXnetFrame^>(handles->Length);
    for (int i = 0; i < handles->Length; i++)
    {
        frames[i] = gcnew NiXnetFrame(handles[i]);
    }
    return frames;
}

NetString NiXnetCluster::Name::get()
{
    return NiXnet::GetDbStringValue(m_handle, nxPropClst_Name);
}

//pdus

bool NiXnetCluster::PdusReqd::get()
{
    return NiXnet::GetDbValue<bool>(m_handle, nxPropClst_PDUsReqd);
}

NiXnetProtocol NiXnetCluster::Protocol::get()
{
   return static_cast<NiXnetProtocol>(NiXnet::GetDbValue<nxDatabaseRef_t>(m_handle, nxPropClst_Protocol));
}

cli::array<NiXnetSignal^>^ NiXnetCluster::Signals::get()
{
    cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_SigRefs);
    cli::array<NiXnetSignal^>^ signals = gcnew cli::array<NiXnetSignal^>(handles->Length);
    for (int i = 0; i < handles->Length; i++)
    {
        signals[i] = gcnew NiXnetSignal(handles[i]);
    }
    return signals;
}

u64 NiXnetCluster::FDBaudRate::get()
{
    return NiXnet::GetDbValue<u64>(m_handle, nxPropClst_CanFdBaudRate64);
}

NiXnetCANIoMode NiXnetCluster::CANIoMode::get()
{
    return static_cast<NiXnetCANIoMode>(NiXnet::GetDbValue<u32>(m_handle, nxPropClst_CanIoMode));
}

NiXnetFdIsoMode NiXnetCluster::CANFdIsoMode::get()
{
    return static_cast<NiXnetFdIsoMode>(NiXnet::GetDbValue<u32>(m_handle, nxPropClst_CanFdIsoMode));
}

cli::array<NiXnetLinSchedule^>^ NiXnetCluster::LinSchedules::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_LINSchedules);
   cli::array<NiXnetLinSchedule^>^ schedules = gcnew cli::array<NiXnetLinSchedule^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      schedules[i] = gcnew NiXnetLinSchedule(handles[i]);
   }
   return schedules;
}

f64 NiXnetCluster::LinTick::get()
{
    return NiXnet::GetDbValue<f64>(m_handle, nxPropClst_LINTick);
}

NetString NiXnetCluster::ToString()
{
   return this->Name;
}
