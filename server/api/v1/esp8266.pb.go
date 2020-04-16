// Code generated by protoc-gen-go. DO NOT EDIT.
// source: esp8266.proto

package v1

import (
	fmt "fmt"
	math "math"

	proto "github.com/golang/protobuf/proto"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

type DataRequest struct {
	Cmd                  uint32   `protobuf:"varint,1,opt,name=cmd,proto3" json:"cmd,omitempty"`
	Adc                  uint32   `protobuf:"varint,2,opt,name=adc,proto3" json:"adc,omitempty"`
	Status               uint32   `protobuf:"varint,3,opt,name=status,proto3" json:"status,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *DataRequest) Reset()         { *m = DataRequest{} }
func (m *DataRequest) String() string { return proto.CompactTextString(m) }
func (*DataRequest) ProtoMessage()    {}
func (*DataRequest) Descriptor() ([]byte, []int) {
	return fileDescriptor_73b2e4f11179e21f, []int{0}
}

func (m *DataRequest) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_DataRequest.Unmarshal(m, b)
}
func (m *DataRequest) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_DataRequest.Marshal(b, m, deterministic)
}
func (m *DataRequest) XXX_Merge(src proto.Message) {
	xxx_messageInfo_DataRequest.Merge(m, src)
}
func (m *DataRequest) XXX_Size() int {
	return xxx_messageInfo_DataRequest.Size(m)
}
func (m *DataRequest) XXX_DiscardUnknown() {
	xxx_messageInfo_DataRequest.DiscardUnknown(m)
}

var xxx_messageInfo_DataRequest proto.InternalMessageInfo

func (m *DataRequest) GetCmd() uint32 {
	if m != nil {
		return m.Cmd
	}
	return 0
}

func (m *DataRequest) GetAdc() uint32 {
	if m != nil {
		return m.Adc
	}
	return 0
}

func (m *DataRequest) GetStatus() uint32 {
	if m != nil {
		return m.Status
	}
	return 0
}

type CmdRequest struct {
	Cmd                  uint32   `protobuf:"varint,1,opt,name=cmd,proto3" json:"cmd,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *CmdRequest) Reset()         { *m = CmdRequest{} }
func (m *CmdRequest) String() string { return proto.CompactTextString(m) }
func (*CmdRequest) ProtoMessage()    {}
func (*CmdRequest) Descriptor() ([]byte, []int) {
	return fileDescriptor_73b2e4f11179e21f, []int{1}
}

func (m *CmdRequest) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_CmdRequest.Unmarshal(m, b)
}
func (m *CmdRequest) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_CmdRequest.Marshal(b, m, deterministic)
}
func (m *CmdRequest) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CmdRequest.Merge(m, src)
}
func (m *CmdRequest) XXX_Size() int {
	return xxx_messageInfo_CmdRequest.Size(m)
}
func (m *CmdRequest) XXX_DiscardUnknown() {
	xxx_messageInfo_CmdRequest.DiscardUnknown(m)
}

var xxx_messageInfo_CmdRequest proto.InternalMessageInfo

func (m *CmdRequest) GetCmd() uint32 {
	if m != nil {
		return m.Cmd
	}
	return 0
}

func init() {
	proto.RegisterType((*DataRequest)(nil), "v1.DataRequest")
	proto.RegisterType((*CmdRequest)(nil), "v1.CmdRequest")
}

func init() {
	proto.RegisterFile("esp8266.proto", fileDescriptor_73b2e4f11179e21f)
}

var fileDescriptor_73b2e4f11179e21f = []byte{
	// 116 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xe2, 0x4d, 0x2d, 0x2e, 0xb0,
	0x30, 0x32, 0x33, 0xd3, 0x2b, 0x28, 0xca, 0x2f, 0xc9, 0x17, 0x62, 0x2a, 0x33, 0x54, 0xf2, 0xe4,
	0xe2, 0x76, 0x49, 0x2c, 0x49, 0x0c, 0x4a, 0x2d, 0x2c, 0x4d, 0x2d, 0x2e, 0x11, 0x12, 0xe0, 0x62,
	0x4e, 0xce, 0x4d, 0x91, 0x60, 0x54, 0x60, 0xd4, 0xe0, 0x0d, 0x02, 0x31, 0x41, 0x22, 0x89, 0x29,
	0xc9, 0x12, 0x4c, 0x10, 0x91, 0xc4, 0x94, 0x64, 0x21, 0x31, 0x2e, 0xb6, 0xe2, 0x92, 0xc4, 0x92,
	0xd2, 0x62, 0x09, 0x66, 0xb0, 0x20, 0x94, 0xa7, 0x24, 0xc7, 0xc5, 0xe5, 0x9c, 0x9b, 0x82, 0xd3,
	0xa4, 0x24, 0x36, 0xb0, 0xad, 0xc6, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x21, 0xa0, 0x12, 0xfb,
	0x86, 0x00, 0x00, 0x00,
}
