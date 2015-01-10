#pragma once

using namespace System;

namespace DatafileGUI {

	public delegate void DatafileChangedEventHandler   (Object^ sender, EventArgs^ e);
	public delegate void DatafileChangedCWDEventHandler(Object^ sender, EventArgs^ e);
};

