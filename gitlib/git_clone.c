#include <stdio.h>
#include <git2.h>
#define GIT_TEST_ROOT ("/home/lion/tmp/git")

static void showGitError(int error);
int main(){
	int error;

	
	git_libgit2_init();
	git_repository *repo = NULL;


	const char * url = "ssh://lvqingfeng@192.168.1.85:29418/All-Projects";
	error=git_clone(&repo,url,GIT_TEST_ROOT,NULL); 
	
	showGitError(error);

	git_repository_free(repo);
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
