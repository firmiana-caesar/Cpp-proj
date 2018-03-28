void CtestDlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码

	//打开一张图片
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, _T("image files (*.bmp; *.jpg)|*.bmp;*.jpg|All Files(*.*)| *.* || "), NULL);
	dlg.m_ofn.lpstrTitle = _T("Open Image");
	if (dlg.DoModal() != IDOK)		//没有选择路径则直接退出
		return;

	//获取图片的路径
	CString m_path = dlg.GetPathName();
	//显示未经修改的图片
	showpicture(m_path);
	//转换图片路径字符串的格式
	std::string strStl;
	strStl = CT2A(m_path);

	//以下六行定义用于检测的颜色的HSV值
	int iLowH = 0;
	int iHighH = 10;
	int iLowS = 43;
	int iHighS = 255;
	int iLowV = 46;
	int iHighV = 255;												
	
	//定义图片存储
	Mat imgOriginal = imread(strStl);
	Mat imgHSV;

	//用向量存储经过HSV处理的图片
	vector<Mat> hsvSplit;
	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

	//通道分离并处理
	split(imgHSV, hsvSplit);
	equalizeHist(hsvSplit[2], hsvSplit[2]);
	merge(hsvSplit, imgHSV);
	Mat imgThresholded;

	//颜色分离
	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);

	//开操作 (去除一些噪点)
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
	
	//闭操作 (连接一些连通域)
	morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

	//进行膨胀操作;i的值根据光照条件进行改变
	for (int i = 0; i < 3; i++)
	{
		dilate(imgThresholded, imgThresholded, element);
	}


	//显示相应的图片
	imshow("Thresholded Image", imgThresholded); 
}
