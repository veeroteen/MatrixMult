#include "Matrix/MatrixMult.h"
#include <chrono>
#include <math.h>

int main()
{
  
   for (int i = 1; i <= 5 ;i++)
   {
      std::cout << "\n\nfor " << i << std::endl;
      size_t size = 1000;
      size = size * i;
      MatrixA *aA, *cA;
      int* matrix = getRawMatrix(size);
      aA = RtoA(matrix, size);

      cA = aA->getTransposed();
      {
         const auto start = std::chrono::steady_clock::now();
         auto b = aA->multiply(*aA);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Linear Array: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/AElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }

      {
         
         const auto start = std::chrono::steady_clock::now();
         auto b = aA->multiplyT(*cA);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Transposed Array: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/ATElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }
      delete aA;
      delete cA;

      
      MatrixAR* aAR, * cAR;
      aAR = RtoAR(matrix,size);
      cAR = aAR->getTransposed();
      {
         const auto start = std::chrono::steady_clock::now();
         auto b = aAR->multiply(*aAR);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Linear ArrayRow: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/ARElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }

      {
            
         const auto start = std::chrono::steady_clock::now();
         auto b = aAR->multiplyT(*cAR);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Transposed ArrayRow: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/ARTElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }
      delete aAR;
      delete cAR;
      

      MatrixV* aV, * cV;
      aV = RtoV(matrix,size);
      cV = aV->getTransposed();

      {
         
         const auto start = std::chrono::steady_clock::now();
         auto b = aV->multiply(*aV);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Linear Vector: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/VElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }

      {
         
         const auto start = std::chrono::steady_clock::now();
         auto b = aV->multiplyT(*cV);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Transposed Vector: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/VTElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }
      delete aV;
      delete cV;
      
      MatrixVR* aVR, * cVR;
      aVR = RtoVR(matrix,size);
      cVR = aVR->getTransposed();
      {
         const auto start = std::chrono::steady_clock::now();
         auto b = aVR->multiply(*aVR);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Linear VectorRow: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/VRlapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }

      {
         const auto start = std::chrono::steady_clock::now();
         auto b = aVR->multiplyT(*cVR);
         const auto end = std::chrono::steady_clock::now();
         auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
         std::cout << "Transposed VectorRow: " << elapsed.count() << std::endl;
         std::ofstream file("Timer/VRTElapsed.txt", i == 1 ? std::ios::ate : std::ios::app);
         file << elapsed.count() << std::endl;
         file.close();
         delete b;
      }
      
      delete aVR;
      delete cVR;
      delete[] matrix;
      
   }
	return 0;
}

