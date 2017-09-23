#include <stdio.h>
#include <git2.h>
#define GIT_TEST_PATH ("/home/lion/git/hosts")
#define GIT_TEST_ROOT ("/home/lion/tmp/git")
static void showGitError(int error);
int main(){
	int error;

	
	git_libgit2_init();
	git_repository *repo = NULL;


	error=git_repository_open(&repo,GIT_TEST_PATH);
	showGitError(error);

	git_libgit2_shutdown();

	return 0;
}


static void showGitError(int error){
	if(error<0){
		const git_error *e = giterr_last();
		printf("error %d/%d:%s\n",error,e->klass,e->message);
		exit(1);
	}
}
