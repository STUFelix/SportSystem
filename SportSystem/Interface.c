#include <stdio.h>
#include <stdlib.h>
void SuperAdministrator(void);
void Administrator(void);
void visitor(void);
void Announcement(void);
void Apply(void);
void Program(void);
void Information(void);
void SeowonInformation(void);
void AthleteInformation(void);
void CompetitionInformation(void);
void CheckScore(void);
void FieldScore(void);
void ContestScore(void);
void CheckGoal(void);
void CheckSeowonGoal(void);
void CheckAthleteGoal(void);
void SetCompetition(void);
void Setting(void);


// 超级管理员界面
void SuperAdministrator() {

	
	
	//1.修改系统设置

	//2.比赛项目设置

	//3.发布秩序册
	
}

// 管理员界面
void Administrator() {
	//1.分区报名

	//2.增删改查分区运动员信息

	//3.

}

// 游客界面
void visitor() {
	//查看结果

}

// 参赛项目发布(全部项目发布)
void Announcement() {

}

// 运动员报名
void Apply() {

}

// 查看秩序册
void Program() {

}

// 参赛信息查询
void Information() {
	// 查看参赛书院信息
	// 查看运动员信息
	// 查看比赛项目
}

// 查看参赛书院信息
void SeowonInformation() {

}

// 查看运动员信息
void AthleteInformation() {

}

// 查看比赛项目(结束报名后的项目发布)
void CompetitionInformation() {
}

// 查看成绩
void CheckScore() {
	// 查看田赛成绩
	// 查看竞赛成绩
}

// 查看田赛成绩
void FieldScore() {
	// 按比赛项目查看成绩
	// 按参赛书院查看成绩
	// 按运动员查看成绩
}

// 查看竞赛成绩
void ContestScore() {
	// 按比赛项目查看成绩
	// 按参赛书院查看成绩
	// 按运动员查看成绩
}

// 查看得分界面
void CheckGoal() {
	// 查看书院得分情况
	// 查看运动员得分
}

// 查看书院得分
void CheckSeowonGoal() {

}

// 查看运动员得分
void CheckAthleteGoal() {

}

// 复查界面
void CheckAgain() {

}

// 比赛项目设置
void SetCompetition() {

}

// 系统设置
void Setting() {

}

int main() {
	int choose;
	printf("Who you are?");
	scanf("%d", &choose);
	setbuf(stdin, NULL);
	while (choose < 1 || choose>3) {
		printf("输入错误，请重新输入:");
		scanf("%d", &choose);
		setbuf(stdin, NULL);
	}
	switch (choose) {
	case 1:
		SuperAdministrator();
		system("pause");
		break;
	case 2:
		Administrator();
		system("pause");

		break;
	case 3:
		visitor();
		system("pause");

		break;
	default:
		break;
	}
}