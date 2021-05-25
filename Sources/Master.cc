#include "Interp/Interp.hh"
#include "Utilities/FlagController.hh"

int main(const int ArgumentCounter, const char** ArgumentValue)
{
  // Flag parsing
  try { Flags.ParseFlag(ArgumentCounter, ArgumentValue); }
  catch(const std::exception& Exception)
  {
    std::cout << Exception.what() << std::endl;
    return EXIT_FAILURE;
  }

  // Helping flag
  if (Flags.ExistFlag("help"))
    return std::cout << Flags.Help() << std::endl, EXIT_SUCCESS;

  DataTable Table;

  // Create interpreter
  try
  {
    if (!Flags.GetFlag("file").length())
      Interp().Live();
    else
      Interp(Flags.GetFlag("file"), Table).Run();
  }
  catch(const std::exception& Exception)
  {
    std::cout << Exception.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
